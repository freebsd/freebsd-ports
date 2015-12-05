# $FreeBSD$

PORTNAME=	fb-adb
DISTVERSION=	1.4.4-115
DISTVERSIONSUFFIX=	-ga682c99
CATEGORIES=	devel
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Better shell for Android devices

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	xxd:${PORTSDIR}/editors/vim-lite \
		${BASH_CMD}:${PORTSDIR}/shells/${BASH_CMD:T}
RUN_DEPENDS=	adb:${PORTSDIR}/devel/android-tools-adb

USE_GITHUB=	yes
GH_ACCOUNT=	facebook

USES=		autoreconf:outsource gmake ncurses perl5 python:3,build
USE_PERL5=	build # pod2man
BASH_CMD?=	bash # can be zsh
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PYTHON3="${PYTHON_CMD}"
# XXX D4158: --mandir as SET_LATE_CONFIGURE_ARGS doesn't respect CONFIGURE_CMD
CONFIGURE_ARGS=	--mandir="${MANPREFIX}/man"
INSTALL_TARGET=	install-strip
PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

# Cross-build sanitization
CONFIG_SITE=	/dev/null # XXX Only for AC_CONFIG_SUBDIRS
CONFIGURE_ENV+=	HOST_CFLAGS="${CPPFLAGS} ${CFLAGS:N-[Og]*:N-pipe}" \
		STUB_CFLAGS="${STUB_CFLAGS}" \
		CPPFLAGS="" CFLAGS="${CFLAGS:M-[Og]*} ${CFLAGS:M-pipe}" \
		HOST_LDFLAGS="${LDFLAGS} ${LIBS}" \
		STUB_LDFLAGS="${STUB_LDFLAGS}" \
		LDFLAGS="" LIBS=""

OPTIONS_DEFINE=	ASSERT BASH DEBUG
OPTIONS_DEFINE_amd64=	NDK
OPTIONS_DEFINE_i386=	NDK
OPTIONS_DEFAULT_amd64=	NDK
OPTIONS_DEFAULT_i386=	NDK
OPTIONS_EXCLUDE_DragonFly=NDK

ASSERT_CONFIGURE_ENABLE=checking
BASH_DESC=		Install JSON parser used by bash-completion
BASH_RUN_DEPENDS=	jq:${PORTSDIR}/textproc/jq
DEBUG_CONFIGURE_ENABLE=	debuggable-stubs

# XXX Convert into USES=android once more things depend on it
NDK_DESC=		Build target stubs using Android NDK
NDK_VARS=		MASTER_SITES+=https://dl.google.com/android/ndk/:ndk
.if defined(ANDROID_NDK)
# Prefer NDK from environment
WRKSRC_ndk=		${ANDROID_NDK}
.else
NDK_DISTFILES=		${DISTNAME_ndk}.bin:ndk,p7zip
DISTNAME_ndk=		android-ndk-r10e-linux-${LINUX_RPM_ARCH:C/i.86/x86/}
WRKSRC_ndk=		${WRKDIR}/${DISTNAME_ndk:C/(-[^-]+){2}$//}
.endif
NDK_BUILD_DEPENDS=	${LINUX_BASE_PORT}
NDK_USE=		LINUX=yes # build
NDK_SHELL=		${SETENV} UNAME_s=Linux UNAME_m=${LINUX_RPM_ARCH} ${SH}
NDK_CONFIGURE_ENV=	ANDROID_NDK="${WRKSRC_ndk}" \
			ANDROID_NDK_SHELL="${NDK_SHELL}" \
			NDK_TMPDIR="${WRKDIR}"
NDK_BUILD_DEPENDS_OFF=	${LOCALBASE}/android/ARMv7/bin/arm-aux-linux-androideabi-gcc:${PORTSDIR}/lang/gnatdroid-armv7 \
			${LOCALBASE}/android-x86/x86_32/bin/i686-aux-linux-android-gcc:${PORTSDIR}/lang/gnatdroid-x86
.if defined(.PARSEDIR)
NDK_CONFIGURE_ENV_OFF=	PATH="${NDK_BUILD_DEPENDS_OFF:C/:.*//:H:ts:}:$$PATH"
.else
NDK_CONFIGURE_ENV_OFF=	PATH="${LOCALBASE}/android/ARMv7/bin:${LOCALBASE}/android-x86/x86_32/bin:$$PATH"
.endif
NDK_CONFIGURE_OFF=	--with-android-ndk=system

post-extract:
# XXX gold: fatal error: a.out: Invalid argument
	@for f in $$(${FIND} ${WRKSRC_ndk} -type l -name '*-ld'); do \
		(cd $${f%/*} && ${LN} -sf $${f##*/}.bfd $${f##*/}); \
	done

post-patch:
# XXX Decouple -Werror from --enable-checking (ASSERT=on)
	@${REINPLACE_CMD} -e '/CPPFLAGS.*-Werror/d' ${WRKSRC}/configure.ac

post-patch-NDK-off:
	@${REINPLACE_CMD} -i '.aux.bak' -e 's/linux-android/aux-&/' \
		${WRKSRC}/stub-*/configure

# XXX D4157: Similar to USES=qmake:outsource, merge into Mk/Uses/autoreconf.mk
.if defined(USES) && ${USES:Mautoreconf\:outsource}
USES:=			autoreconf:build ${USES:Nautoreconf*}
CONFIGURE_CMD=		${AUTORECONF_WRKSRC}/${CONFIGURE_SCRIPT}
CONFIGURE_WRKSRC=	${WRKDIR}/.build
BUILD_WRKSRC=		${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=		${CONFIGURE_WRKSRC}
AUTORECONF_WRKSRC?=	${WRKSRC}

_USES_configure+=	470:do-autoreconf
do-autoreconf:
.for f in AUTHORS ChangeLog INSTALL NEWS README
# Don't modify time stamps if the files already exist
	@test -e ${AUTORECONF_WRKSRC}/${f} || ${TOUCH} ${AUTORECONF_WRKSRC}/${f}
.endfor
	@(cd ${AUTORECONF_WRKSRC} && ${LOCALBASE}/bin/autoreconf -f -i)
	@${MKDIR} ${CONFIGURE_WRKSRC}
.endif

.include <bsd.port.options.mk>

# XXX D4190: Extract :p7zip files with 7z(1) if libarchive cannot handle
# x86_64 self-extracting archive or is too old to have 7zip reader
.if defined(OVERRIDE_LINUX_BASE_PORT) || \
	(${OPSYS} == FreeBSD && ${OSVERSION} < 1000009)
EXTRACT_ONLY+=	${DISTFILES:N*\:*p7zip*:C/:.*//}
EXTRACT_DEPENDS+=${P7ZIP_CMD}:${PORTSDIR}/archivers/p7zip

P7ZIP_CMD?=	7z
P7ZIP_ARGS?=	x -bd -y -o${WRKDIR} >/dev/null

_OPTIONS_extract+=	520:do-p7zip-extract
do-p7zip-extract:
	@for f in ${DISTFILES:M*\:*p7zip*:C/:.*//}; do \
		if ! ${P7ZIP_CMD} ${P7ZIP_ARGS} ${_DISTDIR}/$$f; then \
			return 1; \
		fi; \
	done
.endif

.include <bsd.port.mk>

# XXX Bug 204615: Teach USE_LINUX about build-only deps
.if defined(.PARSEDIR)
RUN_DEPENDS:=	${RUN_DEPENDS:N${LINUX_BASE_PORT}}
.else
RUN_DEPENDS:=	${RUN_DEPENDS:N*linux_base*}
.endif

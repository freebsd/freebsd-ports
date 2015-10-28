# $FreeBSD$

PORTNAME=	fb-adb
DISTVERSION=	1.4.4-109
DISTVERSIONSUFFIX=	-g930ba5f
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Better shell for Android devices

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	xxd:${PORTSDIR}/editors/vim-lite \
		${LOCALBASE}/android/ARMv7/bin/arm-aux-linux-androideabi-gcc:${PORTSDIR}/lang/gnatdroid-armv7 \
		${BASH_CMD}:${PORTSDIR}/shells/${BASH_CMD:T}
RUN_DEPENDS=	adb:${PORTSDIR}/devel/android-tools-adb

USE_GITHUB=	yes
GH_ACCOUNT=	facebook

USES=		autoreconf:outsource gmake ncurses perl5 python:3,build
USE_PERL5=	build # pod2man
BASH_CMD?=	bash # can be zsh
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PATH="${BUILD_DEPENDS:M*android*:C/:.*//:H}:$$PATH" \
		PYTHON3="${PYTHON_CMD}"
# XXX --mandir as SET_LATE_CONFIGURE_ARGS doesn't respect CONFIGURE_CMD
CONFIGURE_ARGS=	--mandir="${MANPREFIX}/man" --with-android-ndk=system
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

ASSERT_CONFIGURE_ENABLE=checking
BASH_DESC=		Install JSON parser used by bash-completion
BASH_RUN_DEPENDS=	jq:${PORTSDIR}/textproc/jq
DEBUG_CONFIGURE_ENABLE=	debuggable-stubs

post-patch:
# XXX Decouple -Werror from --enable-checking (ASSERT=on)
# XXX lang/gnatdroid-x86 doesn't exist yet
	@${REINPLACE_CMD} -e '/CPPFLAGS.*-Werror/d' \
		-e 's/stub-x86[^,]*, //g' \
		${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's/linux-android/aux-&/' \
		${WRKSRC}/stub-*/configure

# XXX Similar to USES=qmake:outsource, merge into Mk/Uses/autoreconf.mk
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

.include <bsd.port.mk>

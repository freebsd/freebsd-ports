PORTNAME=	fb-adb
DISTVERSION=	1.4.4-126
DISTVERSIONSUFFIX=	-g6fd78ae
PORTREVISION=	4
CATEGORIES=	devel comms
.if !defined(ANDROID_NDK)
# XXX Convert into USES=android once more things depend on it
MASTER_SITES=	https://dl.google.com/android/ndk/:7z \
		https://dl.google.com/android/repository/:zip
DISTFILES=	${DISTFILES_${ARCH}}
DISTFILES_i386=	android-ndk-r10e-linux-x86.bin:7z
DISTFILES_amd64=android-ndk-r12b-linux-x86_64.zip:zip
.endif

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	1b5524282981.patch:-p1 \
		8f532a9ee3a3.patch:-p1 \
		a25602788c1b.patch:-p1 \
		3a3a52355a39.patch:-p1 \
		281df4766b82.patch:-p1 \
		723148059ce2.patch:-p1 \
		${NULL}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Better shell for Android devices

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386
IGNORE_DragonFly=	requires linuxulator for Android NDK

BUILD_DEPENDS=	xxd:editors/vim \
		${BASH_CMD}:shells/${BASH_CMD:T}
RUN_DEPENDS=	adb:devel/android-tools-adb

USE_GITHUB=	yes
GH_ACCOUNT=	facebook

USES=		autoreconf gmake linux ncurses perl5 python:3.4+,build
USE_LINUX=	base:build
USE_PERL5=	build # pod2man
BASH_CMD?=	bash # can be zsh
NDK_SHELL=	${LINUXBASE}/bin/sh
# Prefer NDK from environment
WRKSRC_ndk=	${ANDROID_NDK:U${WRKDIR}/${DISTFILES:M*ndk*:R:C/(-[^-]+){2}$//}}
GNU_CONFIGURE=	yes
CONFIGURE_OUTSOURCE=	yes
CONFIGURE_ENV=	PYTHON3="${PYTHON_CMD}"
CONFIGURE_ENV+=	ANDROID_NDK="${WRKSRC_ndk}" \
		ANDROID_NDK_SHELL="${NDK_SHELL}" \
		NDK_TMPDIR="${WRKDIR}"
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
BASH_RUN_DEPENDS=	jq:textproc/jq
DEBUG_CONFIGURE_ENABLE=	debuggable-stubs

post-extract:
# XXX gold: fatal error: a.out: Invalid argument
	@for f in $$(${FIND} ${WRKSRC_ndk} -type l -name '*-ld'); do \
		(cd $${f%/*} && ${LN} -sf $${f##*/}.bfd $${f##*/}); \
	done

post-patch:
# XXX Decouple -Werror from --enable-checking (ASSERT=on)
	@${REINPLACE_CMD} -e '/CPPFLAGS.*-Werror/d' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} 's,mkdir,/compat/linux/../../bin/mkdir,' \
		${WRKSRC_ndk}/build/tools/make-standalone-toolchain.sh \
		${WRKSRC_ndk}/build/tools/ndk-common.sh

.include <bsd.port.mk>

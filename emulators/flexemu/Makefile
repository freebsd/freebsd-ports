PORTNAME=	flexemu
DISTVERSIONPREFIX=	V
DISTVERSION=	3.26
CATEGORIES=	emulators

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	MC6809 emulator running FLEX operating system
WWW=		https://flexemu.neocities.org/

LICENSE=	GPLv2

USES=		compiler desktop-file-utils gl libtool pkgconfig \
		qt:5 shared-mime-info xorg
USE_GITHUB=	yes
GH_ACCOUNT=	aladur
GH_TUPLE=	fmtlib:fmt:0c9fce2:fmt/fmt \
		google:googletest:b514bdc:googletest/googletest \
		open-source-parsers:jsoncpp:8214f71:jsoncpp/jsoncpp
USE_GL=		gl
USE_QT=		buildtools:build core dbus gui network printsupport \
		qmake:build widgets x11extras
USE_XORG=	ice sm x11

GNU_CONFIGURE=	yes

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/rcvflex
	@${RM} ${STAGEDIR}${PREFIX}/bin/send2flx
	@${RM} ${STAGEDIR}${PREFIX}/bin/testdaa

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == gcc
USE_GCC=	yes
CONFIGURE_ARGS=	--disable-precompiled-headers
.endif

.include <bsd.port.post.mk>

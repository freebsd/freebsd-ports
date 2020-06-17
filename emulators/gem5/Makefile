# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gem5
PORTVERSION=	0.0.${DATE}
CATEGORIES=	emulators

MAINTAINER=	ports@FreeBSD.org
COMMENT=	gem5 Simulator System

BUILD_DEPENDS=	swig:devel/swig

BROKEN_armv6=		fails to link: undefined reference to HDLcd::BUS_OPTIONS_RESETV
BROKEN_armv7=		fails to link: undefined reference to HDLcd::BUS_OPTIONS_RESETV
BROKEN_i386=		does not build
BROKEN_mips64=		fails to build: claims that gcc version 4.6 or newer required
BROKEN_FreeBSD_11_powerpc64=	fails to build: claims that gcc version 4.6 or newer required
BROKEN_FreeBSD_12_powerpc64=	fails to build: claims that gcc version 4.6 or newer required

USES=		gmake scons:python2

DATE=		20140422
USE_GITHUB=	yes
GH_ACCOUNT=	CTSRD-CHERI
GH_TAGNAME=	99d65cc

ALL_TARGET=	build/ARM/gem5.opt
MAKE_ENV=	SWIG="${LOCALBASE}/bin/swig"

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|sys/termios.h|termios.h|' \
		${WRKSRC}/src/base/vnc/vncserver.cc \
		${WRKSRC}/src/dev/terminal.cc \
		${WRKSRC}/util/term/term.c

pre-build:
	cd ${WRKSRC} && ${GMAKE} -C util/term

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/${PORTNAME}/ARM
	(cd ${WRKSRC} && ${COPYTREE_SHARE} configs \
		${STAGEDIR}${PREFIX}/${PORTNAME})
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} build/ARM/gem5.opt \
		${STAGEDIR}${PREFIX}/${PORTNAME}/ARM/gem5.opt)
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} util/term/m5term \
		${STAGEDIR}${PREFIX}/bin/m5term)

.include <bsd.port.post.mk>

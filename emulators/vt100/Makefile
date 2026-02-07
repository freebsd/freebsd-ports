PORTNAME=	vt100
DISTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	emulators

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Simulation of VT100 terminal hardware
WWW=		https://github.com/larsbrinkhoff/terminal-simulator

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC:H}/LICENSE

USES=		gl gmake sdl
USE_GITHUB=	yes
GH_ACCOUNT=	larsbrinkhoff
GH_PROJECT=	terminal-simulator
USE_GL=		gl
USE_SDL=	image2
CFLAGS+=	-DSHADERDIR='\"${DATADIR}/\"'
WRKSRC_SUBDIR=	vt100

PLIST_FILES=	bin/vt100
PORTDATA=	crt.shader vertex.shader

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vt100 ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/crt.shader ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/vertex.shader ${STAGEDIR}${DATADIR}/

do-test:
	cd ${WRKSRC:H} && ${SH} test/test.sh

.include <bsd.port.mk>

PORTNAME=	openssn
PORTVERSION=	1.4
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	jessefrgsmith@yahoo.ca
COMMENT=	Modern submarine simulator
WWW=		https://openssn.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		sdl xorg
USE_SDL=	sdl gfx image mixer
USE_XORG=	x11 xau xdmcp xext xmu xpm xxf86vm
WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -E \
		-e '/cp|mkdir/s,\$$\(PREFIX\)|\$$\(DATADIR\),$$(DESTDIR)&,' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>

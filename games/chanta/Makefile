# Created by: Charlie & <root@HellFire.BSD.org.pe>
# $FreeBSD$

PORTNAME=	chanta
PORTVERSION=	0.15
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	http://www.losersjuegos.com.ar/_media/juegos/chanta/descargas/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free 2D jump and run game

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
USE_SDL=	sdl image mixer
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD}
OPTIONS_DEFINE=	DOCS

post-configure:
	@${REINPLACE_CMD} -e 's|-lSDL |`sdl-config --libs` |g' ${WRKSRC}/src/${MAKEFILE}
	@${REINPLACE_CMD} -e 's|^CXXFLAGS|^CXXFLAGS?|g' ${WRKSRC}/src/${MAKEFILE}

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && \
		${INSTALL_DATA} AUTHORS ChangeLog README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

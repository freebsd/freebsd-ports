# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	bumprace
PORTVERSION=	1.5.3
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	http://user.cs.tu-berlin.de/~karlb/bumprace/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Simple arcade racing game

GNU_CONFIGURE=	yes
USES=		gmake
USE_SDL=	sdl mixer image

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/LIBS/ s|-lSDL_[a-z]*|& $${SDL_LIBS}|' ${WRKSRC}/configure

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FAQ ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

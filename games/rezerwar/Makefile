PORTNAME=	rezerwar
PORTVERSION=	0.4.2
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://tamentis.com/projects/rezerwar/files/ \
		https://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Puzzle game involving organizing blocks with pipes
WWW=		https://tamentis.com/projects/rezerwar/

USES=		gmake sdl
USE_SDL=	sdl mixer
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	Unix
CONFIGURE_ENV=	TARGET_BIN=${PREFIX}/bin \
		TARGET_DOC=${DOCSDIR} \
		TARGET_DATA=${DATADIR}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|' ${WRKSRC}/configure

.include <bsd.port.mk>

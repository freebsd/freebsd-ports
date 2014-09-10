# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	boswars
PORTVERSION=	2.6.1
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://www.boswars.org/dist/releases/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	martin@arp242.net
COMMENT=	Futuristic real-time strategy game

LICENSE=	GPLv2

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libtheora.so:${PORTSDIR}/multimedia/libtheora \
		libvorbis.so:${PORTSDIR}/audio/libvorbis

USES=		lua:51 scons
USE_SDL=	sdl
USE_GL=		yes
MAKE_ARGS+=	opengl=1
CPPPATH=	${LOCALBASE}/include ${LUA_INCDIR}
LIBPATH=	${LOCALBASE}/lib ${LUA_LIBDIR}
CFLAGS+=	-DSTRATAGUS_LIB_PATH='"\"${DATADIR}\""'

DESKTOP_ENTRIES=	"Bos Wars" "${COMMENT}" "" \
			"boswars" "Game;StrategyGame;" false

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '\
		s|-pthread|${PTHREAD_LIBS}|g; \
		s|/usr/local|${LOCALBASE}|g; \
		s|lua51|lua-${LUA_VER}|g;' \
	${WRKSRC}/SConstruct

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
.for f in campaigns graphics intro languages maps patches scripts sounds units
	${CP} -R ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}
	${COPYTREE_SHARE} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

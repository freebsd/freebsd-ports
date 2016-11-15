# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	boswars
PORTVERSION=	2.6.1
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	http://www.boswars.org/dist/releases/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	martin@arp242.net
COMMENT=	Futuristic real-time strategy game

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libpng.so:graphics/png \
		libtheora.so:multimedia/libtheora \
		libvorbis.so:audio/libvorbis

USES=		lua:51 scons shebangfix
SHEBANG_FILES=	languages/updatepo.sh
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
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	irrlamb
PORTVERSION=	0.1.0
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	3D physics-based puzzle game

LIB_DEPENDS=	libsqlite3.so:${PORTSDIR}/databases/sqlite3
BUILD_DEPENDS=	${LOCALBASE}/lib/libIrrlicht.so:${PORTSDIR}/x11-toolkits/irrlicht
RUN_DEPENDS=	${LOCALBASE}/lib/libIrrlicht.so:${PORTSDIR}/x11-toolkits/irrlicht

USES=		scons dos2unix lua:51
DOS2UNIX_FILES=	src/engine/save.h src/objects/orb.cpp src/objects/player.cpp \
		src/engine/state.h

CPPPATH=	${LOCALBASE}/include ${LUA_INCDIR}
LIBPATH=	${LOCALBASE}/lib ${LUA_LIBDIR}

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*
PORTDATA=	*

DATA_DIRS=	art campaigns collision fonts levels meshes scenes scripts textures

post-patch:
.for dir in ${DATA_DIRS}
	@${REINPLACE_CMD} -e 's|"\(${dir}/\)|"${DATADIR}/\1|' \
		${WRKSRC}/src/*.cpp ${WRKSRC}/src/engine/*.cpp \
		${WRKSRC}/src/objects/*.cpp ${WRKSRC}/meshes/*.irrmesh \
		${WRKSRC}/scenes/*.irr
.endfor
	@${REINPLACE_CMD} -e "s/lua/lua-${LUA_VER}/g" ${WRKSRC}/SConstruct
	@${FIND} ${WRKSRC} -name "*.bak" -delete

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/irrlamb ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${DATA_DIRS}" ${STAGEDIR}${DATADIR}/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} readme.txt changelog.txt ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>

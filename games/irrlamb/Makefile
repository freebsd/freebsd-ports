# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	irrlamb
PORTVERSION=	0.1.0
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	3D physics-based puzzle game

LIB_DEPENDS=	sqlite3:${PORTSDIR}/databases/sqlite3
BUILD_DEPENDS=	${LOCALBASE}/lib/libIrrlicht.so:${PORTSDIR}/x11-toolkits/irrlicht
RUN_DEPENDS=	${LOCALBASE}/lib/libIrrlicht.so:${PORTSDIR}/x11-toolkits/irrlicht

USE_LUA=	5.1+
USE_SCONS=	yes
MAKE_JOBS_SAFE=	yes

CPPPATH=	${LOCALBASE}/include ${LUA_INCDIR}
LIBPATH=	${LOCALBASE}/lib ${LUA_LIBDIR}

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	readme.txt changelog.txt
PORTDATA=	*

PLIST_FILES=	bin/${PORTNAME}

DATA_DIRS=	art campaigns collision fonts levels meshes scenes scripts textures

.include <bsd.port.options.mk>

post-patch:
.for dir in ${DATA_DIRS}
	@${REINPLACE_CMD} -e 's|"\(${dir}/\)|"${DATADIR}/\1|' \
		${WRKSRC}/src/*.cpp ${WRKSRC}/src/engine/*.cpp \
		${WRKSRC}/src/objects/*.cpp ${WRKSRC}/meshes/*.irrmesh \
		${WRKSRC}/scenes/*.irr
.endfor
	@${FIND} ${WRKSRC} -name "*.bak" -delete

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/irrlamb ${PREFIX}/bin
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${DATA_DIRS}" ${DATADIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>

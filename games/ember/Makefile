# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ember
PORTVERSION=	0.7.2
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF/worldforge/Ember%20%28OGRE%20client%29/${PORTVERSION} \
		http://amber.worldforge.org/ember/releases/stable/
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-media-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Ember is a WorldForge 3D client using the OGRE 3D library

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/lib/libOgreMain.so:graphics/ogre3d
RUN_DEPENDS=	${LOCALBASE}/lib/libOgreMain.so:graphics/ogre3d
LIB_DEPENDS=	libsigc-2.0.so:devel/libsigc++20 \
		liberis-1.3.so:devel/eris \
		libvarconf-1.0.so:devel/varconf \
		libmercator-0.3.so:devel/mercator \
		libwfut-0.2.so:devel/libwfut \
		libboost_thread.so:devel/boost-libs \
		libCEGUIBase-0.so:graphics/cegui

CONFIGURE_ARGS=	--with-png-prefix=${LOCALBASE} --enable-binreloc \
		--program-transform-name= --disable-cppunit --disable-debug \
		--with-boost=${LOCALBASE} --with-toluaxx=${TOLUAXX_CMD}
CONFIGURE_ENV+=	LUA_LIBS="-L${LUA_LIBDIR} -llua-${LUA_VER}" \
		LUA_CFLAGS="-I${LUA_INCDIR}" \
		TOLUAXX="${TOLUAXX_CMD}"

TOLUAXX_CMD=	${LOCALBASE}/bin/tolua++${LUA_VER}
USE_SDL=	sdl
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		openal:al,alut pathfix pkgconfig compiler:c++11-lib tar:bzip2 lua:51

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '\
		s|-lGL|-L${LOCALBASE}/lib -lGL|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|	install-dist_docDATA |	|g'  ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|#plugindir=.*|plugindir="${LOCALBASE}/lib/OGRE"|; \
		s|,Plugin_CgProgramManager||g' \
		${WRKSRC}/ember.conf
	@${REINPLACE_CMD} -e 's|std::lround|lround|g' \
		${WRKSRC}/src/components/ogre/terrain/TerrainPageGeometry.cpp \
		${WRKSRC}/src/components/ogre/terrain/HeightMap.cpp

post-install:
	(cd ${WRKDIR}/ember-media-${PORTVERSION}/media && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/media)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docfile in README.md COPYING AUTHORS ChangeLog
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

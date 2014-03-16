# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ember
PORTVERSION=	0.7.0
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/worldforge/Ember%20%28OGRE%20client%29/${PORTVERSION} \
		http://amber.worldforge.org/ember/releases/stable/
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-media-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Ember is a WorldForge 3D client using the OGRE 3D library

BUILD_DEPENDS=	${LOCALBASE}/lib/libOgreMain.so.1.8.1:${PORTSDIR}/graphics/ogre3d
RUN_DEPENDS=	${LOCALBASE}/lib/libOgreMain.so.1.8.1:${PORTSDIR}/graphics/ogre3d
LIB_DEPENDS=	libsigc-2.0.so:${PORTSDIR}/devel/libsigc++20 \
		liberis-1.3.so:${PORTSDIR}/devel/eris \
		libvarconf-1.0.so:${PORTSDIR}/devel/varconf \
		libmercator-0.3.so:${PORTSDIR}/devel/mercator \
		libwfut-0.2.so:${PORTSDIR}/devel/libwfut \
		libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libCEGUIBase-0.7.9.so:${PORTSDIR}/graphics/cegui

CONFIGURE_ARGS=	--with-png-prefix=${LOCALBASE} --enable-binreloc \
		--program-transform-name= --disable-cppunit --disable-debug \
		--with-toluaxx=${TOLUAXX_CMD}
CONFIGURE_ENV+=	LUA_LIBS="-L${LUA_LIBDIR} -llua" \
		LUA_CFLAGS="-I${LUA_INCDIR}" \
		TOLUAXX="${TOLUAXX_CMD}"

USE_SDL=	sdl
GNU_CONFIGURE=	YES
USE_LDCONFIG=	YES
USE_LUA=	5.1
LUA_COMPS=	toluaxx
USES=		openal:al,alut pathfix pkgconfig
USE_BZIP2=	YES
CPPFLAGS+=	-DBR_NO_MACROS -std=c++11
USE_GCC=	yes

NO_STAGE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '\
		s|-lGL|-L${LOCALBASE}/lib -lGL|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|	install-dist_docDATA |	|g'  ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|$$(sysconfdir)/ember/|$$(sysconfdir)/ember|g' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/src/components/ogre/Makefile.in
	@${REINPLACE_CMD} -e 's|#plugindir=.*|plugindir="${LOCALBASE}/lib/OGRE"|; \
		s|,Plugin_CgProgramManager||g' \
		${WRKSRC}/ember.conf
	@${REINPLACE_CMD} -e 's|/bash|/sh|g' ${WRKSRC}/ember.in
	@${REINPLACE_CMD} -e 's|BOOST_THREAD_LIB =|& -L${_GCC_RUNTIME} -lstdc++ |g' \
		${WRKSRC}/src/main/Makefile.in
	@${REINPLACE_CMD} -e 's|reset(0)|reset()|g' \
		${WRKSRC}/src/components/ogre/SceneManagers/EmberPagingSceneManager/src/OgrePagingLandScapeData2D.cpp

post-install:
	(cd ${WRKDIR}/ember-media-${PORTVERSION}/media && ${FIND} . -type f -print | \
		${CPIO} -pdmu -R${SHAREOWN}:${SHAREGRP} ${DATADIR}/media)
	${FIND} ${DATADIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 0755
	${FIND} ${DATADIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 0644

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for docfile in README COPYING AUTHORS ChangeLog TODO
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

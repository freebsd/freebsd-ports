# New ports collection makefile for:	ember
# Date created:				03 Oct 2005
# Whom:					Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ember
PORTVERSION=	0.4.0
PORTREVISION=	0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://amber.worldforge.org/ember/releases/stable/
MASTER_SITE_SUBDIR=worldforge

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Ember is a WorldForge 3d client using the OGRE 3d library

RUN_DEPENDS=	${X11BASE}/bin/WFUT.jar:${PORTSDIR}/devel/wfut
LIB_DEPENDS=	sigc-2.0:${PORTSDIR}/devel/libsigc++20 \
		OgreMain.10:${PORTSDIR}/graphics/ogre3d \
		eris-1.3:${PORTSDIR}/devel/eris \
		varconf-1.0.6:${PORTSDIR}/devel/varconf \
		mercator-0.2.4:${PORTSDIR}/devel/mercator \
		openal.0:${PORTSDIR}/audio/openal \
		alut.0:${PORTSDIR}/audio/freealut

CONFIGURE_ARGS=	--with-png-prefix=${LOCALBASE} --enable-binreloc --program-transform-name= --disable-cppunit
USE_SDL=	sdl image
GNU_CONFIGURE=	YES
INSTALLS_SHLIB=	YES
USE_GCC=	3.4
USE_X_PREFIX=	YES
USE_GNOME=	gnomehack
USE_BZIP2=	YES
CPPFLAGS=	-DBR_NO_MACROS

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e '\
		s|sdl-config|${SDL_CONFIG}|g; \
		s|"-lIL|"-L${LOCALBASE}/lib -lIL|g; \
		s|CEGUI-OGRE_\([A-Z]*=\)|CEGUI_OGRE_\1|g; \
		s|\$$CEGUI-OGRE_\([A-Z]*\)|\$$CEGUI_OGRE_\1|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '\
		s|^CFLAGS =.*|& $${SDL_CFLAGS} -I${X11BASE}/include|g' \
		${WRKSRC}/src/framework/Makefile.in
	@${REINPLACE_CMD} -e '\
		s|<SDL/|<|g; \
		s|libSDL_image-1\.2\.so\.0|libSDL_image\.so|g' \
		${WRKSRC}/configure \
		${WRKSRC}/src/components/ogre/EmberOgre.cpp \
		${WRKSRC}/src/framework/scrap.c
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|' \
		${WRKSRC}/src/components/ogre/SceneManagers/EmberPagingSceneManager/src/filetutils.cpp
	@${REINPLACE_CMD} -e 's|	install-dist_docDATA |	|g'  ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '\
		 /Plugin=Plugin_CgProgramManager.so/d; \
		s|/usr/lib/OGRE|${X11BASE}/lib/OGRE|' \
		${WRKSRC}/src/components/ogre/plugins.cfg
	@${REINPLACE_CMD} -e 's|/altypes\.h|/al\.h|' \
		${WRKSRC}/src/services/sound/SoundService.h
	@${REINPLACE_CMD} -e 's|@LDFLAGS@|& -lopenal -lalut|' \
		${WRKSRC}/src/components/ogre/Makefile.in
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|lrintf|(long int)rintf|g' \
		${WRKSRC}/src/components/ogre/environment/meshtree/TStem.cpp \
		${WRKSRC}/src/components/ogre/EmberEntityFactory.cpp
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docfile in README COPYING AUTHORS ChangeLog TODO
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>

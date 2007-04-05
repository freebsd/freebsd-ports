# New ports collection makefile for:	ember
# Date created:				03 Oct 2005
# Whom:					Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ember
PORTVERSION=	0.4.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://amber.worldforge.org/ember/releases/stable/
MASTER_SITE_SUBDIR=worldforge
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-media-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Ember is a WorldForge 3d client using the OGRE 3d library

LIB_DEPENDS=	sigc-2.0:${PORTSDIR}/devel/libsigc++20 \
		OgreMain.13:${PORTSDIR}/graphics/ogre3d \
		eris-1.3:${PORTSDIR}/devel/eris \
		varconf-1.0.6:${PORTSDIR}/devel/varconf \
		mercator-0.2.4:${PORTSDIR}/devel/mercator \
		openal.0:${PORTSDIR}/audio/openal \
		alut.1:${PORTSDIR}/audio/freealut \
		wfut-0.1.0:${PORTSDIR}/devel/libwfut

CONFIGURE_ARGS=	--with-png-prefix=${LOCALBASE} --enable-binreloc --program-transform-name= --disable-cppunit --enable-debug
USE_SDL=	sdl
GNU_CONFIGURE=	YES
INSTALLS_SHLIB=	YES
USE_X_PREFIX=	YES
USE_GNOME=	gnomehack
USE_BZIP2=	YES
CPPFLAGS=	-DBR_NO_MACROS

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
IGNORE=		Does not compile because of inlining error
.endif

post-patch:
	@${REINPLACE_CMD} -e '\
		s|sdl-config|${SDL_CONFIG}|g; \
		s|"-lIL|"-L${LOCALBASE}/lib -lIL|g; \
		s|-lGL|-L${X11BASE}/lib -lGL|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|^CFLAGS =.*|& $${SDL_CFLAGS} -I${X11BASE}/include|g' \
		${WRKSRC}/src/framework/Makefile.in
	@${REINPLACE_CMD} -e 's|<SDL/|<|g' \
		${WRKSRC}/src/components/ogre/OgreSetup.cpp \
		${WRKSRC}/src/framework/scrap.c
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|' \
		${WRKSRC}/src/components/ogre/SceneManagers/EmberPagingSceneManager/src/filetutils.cpp
	@${REINPLACE_CMD} -e 's|	install-dist_docDATA |	|g'  ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '\
		 /Plugin=Plugin_CgProgramManager.so/d; \
		s|/usr/lib/OGRE|${X11BASE}/lib/OGRE|' \
		${WRKSRC}/src/components/ogre/plugins.cfg
	@${REINPLACE_CMD} -e 's|@LDFLAGS@|& -lopenal -lalut|' \
		${WRKSRC}/src/components/ogre/Makefile.in

post-install:
	(cd ${WRKDIR}/${PORTNAME}-media-${PORTVERSION} && ${FIND} . -type f -print | \
		${CPIO} -pdmu -R${SHAREOWN}:${SHAREGRP} ${DATADIR})
	${FIND} ${DATADIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 0755
	${FIND} ${DATADIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 0644
	
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docfile in README COPYING AUTHORS ChangeLog TODO
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>

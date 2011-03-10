# New ports collection makefile for:	ember
# Date created:				03 Oct 2005
# Whom:					Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ember
PORTVERSION=	0.6.0
CATEGORIES=	games
MASTER_SITES=	SF/worldforge/Ember%20%28OGRE%20client%29/${PORTVERSION} \
		http://amber.worldforge.org/ember/releases/stable/

DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-media-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Ember is a WorldForge 3d client using the OGRE 3d library

BUILD_DEPENDS=	${LOCALBASE}/lib/libOgreMain.so.1.7.2:${PORTSDIR}/graphics/ogre3d
RUN_DEPENDS=	${LOCALBASE}/lib/libOgreMain.so.1.7.2:${PORTSDIR}/graphics/ogre3d
LIB_DEPENDS=	sigc-2.0:${PORTSDIR}/devel/libsigc++20 \
		eris-1.3:${PORTSDIR}/devel/eris \
		varconf-1.0.6:${PORTSDIR}/devel/varconf \
		mercator-0.2.8:${PORTSDIR}/devel/mercator \
		wfut-0.2:${PORTSDIR}/devel/libwfut \
		boost_thread.4:${PORTSDIR}/devel/boost-libs \
		CEGUIBase-0.7.5:${PORTSDIR}/graphics/cegui

CONFIGURE_ARGS=	--with-png-prefix=${LOCALBASE} --enable-binreloc \
		--program-transform-name= --disable-cppunit --enable-debug \
		--with-toluaxx=${TOLUAXX_CMD}
CONFIGURE_ENV+=	LUA_LIBS="-L${LUA_LIBDIR} -llua" \
		LUA_CFLAGS="-I${LUA_INCDIR}" \
		TOLUAXX="${TOLUAXX_CMD}"
USE_SDL=	sdl
GNU_CONFIGURE=	YES
USE_LDCONFIG=	YES
USE_LUA=	5.1
LUA_COMPS=	toluaxx
USE_OPENAL=	al alut
USE_GNOME=	gnomehack
USE_BZIP2=	YES
CPPFLAGS=	-DBR_NO_MACROS
MAKE_JOBS_SAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e '\
		s|sdl-config|${SDL_CONFIG}|g; \
		s|"-lIL|"-L${LOCALBASE}/lib -lIL|g; \
		s|-lGL|-L${LOCALBASE}/lib -lGL|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|^CFLAGS =.*|& $${SDL_CFLAGS} -I${LOCALBASE}/include|g' \
		${WRKSRC}/src/framework/Makefile.in
	@${REINPLACE_CMD} -e 's|sighandler_t|sig_t|g' \
		${WRKSRC}/src/components/ogre/OgreSetup.cpp
	@${REINPLACE_CMD} -e 's|	install-dist_docDATA |	|g'  ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|$$(sysconfdir)/ember/|$$(sysconfdir)/ember|g' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/src/components/ogre/Makefile.in
	@${REINPLACE_CMD} -e 's|#plugindir=.*|plugindir="${LOCALBASE}/lib/OGRE"|; \
		s|,Plugin_CgProgramManager||g' \
		${WRKSRC}/ember.conf

post-install:
	(cd ${WRKDIR}/media-${PORTVERSION}/media && ${FIND} . -type f -print | \
		${CPIO} -pdmu -R${SHAREOWN}:${SHAREGRP} ${DATADIR}/media)
	${FIND} ${DATADIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 0755
	${FIND} ${DATADIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 0644

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docfile in README COPYING AUTHORS ChangeLog TODO
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

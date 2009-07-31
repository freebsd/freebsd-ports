# New ports collection makefile for:	ember
# Date created:				03 Oct 2005
# Whom:					Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ember
PORTVERSION=	0.5.6
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF \
		http://amber.worldforge.org/ember/releases/stable/
MASTER_SITE_SUBDIR=worldforge
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-media-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Ember is a WorldForge 3d client using the OGRE 3d library

BUILD_DEPENDS=	${LOCALBASE}/lib/libOgreMain-1.6.2.so:${PORTSDIR}/graphics/ogre3d
RUN_DEPENDS=	${LOCALBASE}/lib/libOgreMain-1.6.2.so:${PORTSDIR}/graphics/ogre3d
LIB_DEPENDS=	sigc-2.0:${PORTSDIR}/devel/libsigc++20 \
		eris-1.3:${PORTSDIR}/devel/eris \
		varconf-1.0.6:${PORTSDIR}/devel/varconf \
		mercator-0.2.6:${PORTSDIR}/devel/mercator \
		openal.0:${PORTSDIR}/audio/openal \
		alut.1:${PORTSDIR}/audio/freealut \
		wfut-0.2:${PORTSDIR}/devel/libwfut

CONFIGURE_ARGS=	--with-png-prefix=${LOCALBASE} --enable-binreloc --program-transform-name= --disable-cppunit --enable-debug
CONFIGURE_ENV+=	LUA_LIBS="-L${LUA_LIBDIR} -llua" \
		LUA_CFLAGS="-I${LUA_INCDIR}"
USE_SDL=	sdl
GNU_CONFIGURE=	YES
USE_LDCONFIG=	YES
USE_LUA=	5.1
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

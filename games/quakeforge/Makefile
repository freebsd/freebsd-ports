# New ports collection makefile for:	QuakeForge
# Date created:		4 January 2000
# Whom:			darius@dons.net.au
#
# $FreeBSD$
#

PORTNAME=	QuakeForge
PORTVERSION=	0.1.1
CATEGORIES=	games
MASTER_SITES=	http://download.sourceforge.net/quake/
DISTNAME=	quakeforge-${PORTVERSION}

MAINTAINER=	darius@dons.net.au

BUILD_DEPENDS=	aclocal:${PORTSDIR}/devel/automake
LIB_DEPENDS=	SDL-1.0.2:${PORTSDIR}/devel/sdl \
		${GL_DEPENDS}

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOCONF=	yes
USE_XLIB=	yes
PLIST=		${WRKDIR}/PLIST
AUTOCONF=       ${WRKSRC}/bootstrap

BINARIES=       quake-x11 quake-sdl qw-client-x11 qw-client-sdl qw-server

CONFIGURE_ARGS= "--with-sdl=${LOCALBASE}"
CONFIGURE_ENV=	"SDL_LIBS=`sdl-config --libs`" \
		"SDL_CFLAGS=`sdl-config --cflags`"

.if defined(USE_GLX)
GL_DEPENDS=	GL.1:${PORTSDIR}/graphics/glx
BINARIES+=      quake-gl qw-client-gl
.else
GL_DEPENDS=
CONFIGURE_ARGS+=--without-opengl
.endif

pre-configure:
	@${CP} ${PKGDIR}/PLIST ${PLIST}
.if defined(USE_GLX)
	${CAT} ${PKGDIR}/PLIST.glx >>${PLIST}
.else
	@${ECHO_MSG} "Define USE_GLX to use GLX (otherwise it is explicitly disabled!)"
.endif

do-install:
.for binary in ${BINARIES}
	${INSTALL_PROGRAM} ${WRKSRC}/targets/${binary} ${PREFIX}/bin/
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/quakeforge
	cd ${WRKSRC}/doc && \
		${INSTALL_MAN} README.* *.txt ${PREFIX}/share/doc/quakeforge
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	QuakeForge
# Date created:		4 January 2000
# Whom:			darius@dons.net.au
#
# $FreeBSD$
#

PORTNAME=	QuakeForge
PORTVERSION=	0.1.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	quake
DISTNAME=	quakeforge-${PORTVERSION}
.if !defined(NO_WAD)
MASTER_SITES+=	http://www.devolution.com/~slouken/SDL/projects/quake/data/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${WADFILE}
.endif

MAINTAINER=	darius@dons.net.au

BUILD_DEPENDS=	aclocal:${PORTSDIR}/devel/automake
LIB_DEPENDS=	SDL-1.0.2:${PORTSDIR}/devel/sdl10 \
		${GL_DEPENDS}

SDL_CONFIG?=	${LOCALBASE}/bin/sdl-config

WADFILE=	quakesw-1.0.6.tar.gz
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOCONF=	yes
USE_XLIB=	yes
PLIST=		${WRKDIR}/PLIST

BINARIES=	quake-x11 quake-sdl qw-client-x11 qw-client-sdl qw-server

CONFIGURE_ARGS= "--with-sdl=${LOCALBASE}"
CONFIGURE_ENV=	"SDL_LIBS=`${SDL_CONFIG} --libs`" \
		"SDL_CFLAGS=`${SDL_CONFIG} --cflags`"

.if defined(WITH_GLX)
GL_DEPENDS=	GL.1:${PORTSDIR}/graphics/utah-glx
BINARIES+=	quake-gl qw-client-gl
.else
GL_DEPENDS=
CONFIGURE_ARGS+=--without-opengl
.endif
.if !defined(NO_WAD)
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
BINDIR=		${PREFIX}/share/quakeforge
.else
BINDIR=		${PREFIX}/bin
.endif

pre-configure:
.if !defined(WITH_GLX)
	@${ECHO_MSG} "Define WITH_GLX to use GLX (otherwise it is explicitly disabled!)"
.endif
	@cd ${WRKSRC} ; ${ACLOCAL}
	@cd ${WRKSRC} ; ${AUTOHEADER}

do-install:
	@${CP} ${PKGDIR}/pkg-plist ${PLIST}

.if defined(WITH_GLX)
	@${CAT} ${PKGDIR}/pkg-plist.glx >>${PLIST}
.endif

.if !defined(NO_WAD)
	${MKDIR} ${PREFIX}/share/quakeforge
	${TAR} xfz ${DISTDIR}/${WADFILE} -C ${PREFIX}/share/quakeforge
.for binary in ${BINARIES}
	@printf "#!/bin/sh\ncd ${PREFIX}/share/quakeforge\n./${binary} \$$@" > \
		${WRKDIR}/${binary}.sh
	${INSTALL_SCRIPT} ${WRKDIR}/${binary}.sh ${PREFIX}/bin/${binary}
	@${ECHO} share/quakeforge/${binary} >>${PLIST}
.endfor
	@${CAT} ${PKGDIR}/pkg-plist.wad >>${PLIST}
.endif

.for binary in ${BINARIES}
	${INSTALL_PROGRAM} ${WRKSRC}/targets/${binary} ${BINDIR}/
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/quakeforge
	cd ${WRKSRC}/doc && \
		${INSTALL_MAN} README.* *.txt ${PREFIX}/share/doc/quakeforge
.endif

.include <bsd.port.mk>

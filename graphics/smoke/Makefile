# New ports collection makefile for: smoke
# Date created:		05 Feb 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	smoke
PORTVERSION=	0.5.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.chem.pwf.cam.ac.uk/~jdh30/programming/opengl/smoke/code/

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	Vector graphics OpenGL renderer

BUILD_DEPENDS=	${LOCALBASE}/bin/tmake:${PORTSDIR}/devel/tmake
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_SDL=	yes
USE_GL=		yes
USE_X_PREFIX=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

FREETYPE_CONFIG?=	${LOCALBASE}/bin/freetype-config
SDL_CONFIG?=		${LOCALBASE}/bin/sdl11-config
TMAKE?=			${LOCALBASE}/bin/tmake
TMAKEPATH?=		${LOCALBASE}/share/tmake/freebsd-g++

PORTDOCS=	README

pre-everything::
	@${ECHO_MSG} "This port depends on SDL with OpenGL support."
	@${ECHO_MSG} "If your SDL does not support OpenGL, hit ^C now and reinstall SDL"
	@${ECHO_MSG} "with OpenGL support turned on."

pre-configure:
	@${REINPLACE_CMD} -e "s|%%FREETYPE_CONFIG%%|${FREETYPE_CONFIG}|g; \
		s|%%SDL_CONFIG%%|${SDL_CONFIG}|g; \
		s#%%FREETYPE_INCLUDEPATH%%#`${FREETYPE_CONFIG} --cflags | ${SED} -e 's|-I||g'`#; \
		s#%%SDL_INCLUDEPATH%%#`${SDL_CONFIG} --cflags | ${SED} -e 's|-I||g; s|-D[[:graph:]]*||g'`#; \
		s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g" \
		${WRKSRC}/project

pre-build:
	${SETENV} TMAKEPATH=${TMAKEPATH} \
		${TMAKE} ${WRKSRC}/project >${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/smoke ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${EXAMPLESDIR}/tests
	${INSTALL_DATA} ${WRKSRC}/tests/tiger.* ${EXAMPLESDIR}/tests
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>

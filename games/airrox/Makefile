# New ports collection makefile for:	airrox
# Date created:				12 Jul 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	airrox
PORTVERSION=	0.0.4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-0.04

MAINTAINER=	alejandro@varnet.biz
COMMENT=	An 3D Air Hockey, which uses SDL & OpenGL

LIB_DEPENDS=	glut.3:${PORTSDIR}/graphics/libglut

USE_GMAKE=	yes
USE_SDL=	mixer net sdl
USE_GL=		yes
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ''

WRKSRC=		${WRKDIR}/${PORTNAME}/source

OPTIONS=	OPTIMIZED_CFLAGS "Enable compilation optimizations" on

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

ALL_TARGET=	linux

DATADIRS=	audio icones imagens meshs texturas

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		need sscanf() interface in libc
.endif

post-patch:
# Fix Makefile
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${X11BASE}|g ; \
			s|-lSDL ||g ; \
			s|-lpthread||g ; \
			s|sdl-config|${SDL_CONFIG}|g ; \
			s|\(-O2\)|${CFLAGS} -I${X11BASE}/include \
			`${SDL_CONFIG} --cflags` \1| ; \
			s|$$(INCLUDEWIN)||g ; \
			s|g++|${CXX}|g' \
				${WRKSRC}/${MAKEFILE}

# Fix SDL include statement
.for f in *.cpp *.h
	@${FIND} ${WRKSRC} -type f -name "${f}" -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -e \
		's|\(#include.*\)SDL/\(SDL.*\)|\1\2|'
.endfor

# Fix paths to ${DATADIR}
.for d in ${DATADIRS}
	@${REINPLACE_CMD} -e 's|../\(${d}/\)|${DATADIR}/\1|' \
				${WRKSRC}/*.cpp ${WRKSRC}/*.h
.endfor

# Enable/disable compilation optimizations
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${MAKEFILE}
.endif

do-install:
# Program
	@${INSTALL_PROGRAM} ${WRKSRC}/air ${PREFIX}/bin/${PORTNAME}

# Data
	@${MKDIR} ${DATADIR}

# Data: directories
.for d in ${DATADIRS}
	@${CP} -R ${WRKDIR}/${PORTNAME}/${d} ${DATADIR}
.endfor

# Data: config.txt
	@${INSTALL_DATA} ${WRKSRC}/config.txt ${DATADIR}

# Remove CVS directories
	@${FIND} ${DATADIR} -type d -name "CVS" -print0 | \
		${XARGS} -0 ${RM} -rf

# Documentation (optional)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${FILESDIR}/readme.txt ${DOCSDIR}
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>

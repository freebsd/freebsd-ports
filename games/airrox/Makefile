# New ports collection makefile for:	airrox
# Date created:				12 Jul 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	airrox
PORTVERSION=	0.0.4
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-0.04

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An 3D Air Hockey, which uses SDL & OpenGL

DEPRECATED=	development has ceased
EXPIRATION_DATE=	2011-04-11

USE_GMAKE=	yes
USE_SDL=	mixer net sdl
USE_GL=		glut
REINPLACE_ARGS=	-i ''
ALL_TARGET=	linux
WRKSRC=		${WRKDIR}/${PORTNAME}/source

OPTIONS=	OPTIMIZED_CFLAGS "Enable compilation optimizations" on

SUB_FILES=	pkg-message

DIRS=		audio icones imagens meshs texturas

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
MAKE_ENV+=	OPTIMIZED_CFLAGS=yes
.endif

post-extract:
	@${FIND} ${WRKDIR} -type d -name CVS -print0 | ${XARGS} -0 ${RM} -rf

post-patch:
.for d in ${DIRS}
	@${REINPLACE_CMD} -e 's|../\(${d}/\)|${DATADIR}/\1|' \
		${WRKSRC}/*.cpp ${WRKSRC}/*.h
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/air ${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${DATADIR}
.for d in ${DIRS}
	${CP} -R ${WRKDIR}/${PORTNAME}/${d} ${DATADIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/config.txt ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/readme.txt ${DOCSDIR}
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>

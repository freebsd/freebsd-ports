# New ports collection makefile for:	glexcess
# Date created:			1 September 2006
# Whom:				Hernan Di Pietro <hernan.di.pietro@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	glexcess
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://www.glexcess.com/files/
DISTNAME=	${PORTNAME}

MAINTAINER=	hernan.di.pietro@gmail.com
COMMENT=	An impressive OpenGL Demo


USE_GL=		glut

MAKE_ARGS=	'CXXFLAGS=${CXXFLAGS} -I${LOCALBASE}/include -pipe -s -O2' \
		'LDFLAGS=-L${LOCALBASE}/lib -lGL -lGLU -lglut'

post-patch:
	@${REINPLACE_CMD} -e 's|data/|${DATADIR}/|' ${WRKSRC}/scene*.cpp
	@${REINPLACE_CMD} -e 's|k_InitGL(GLvoid)|k_InitGL(void)|' ${WRKSRC}/scene12.cpp
	@${REINPLACE_CMD} -e 's|Load(char\*|Load(const char* |g' ${WRKSRC}/Texture.*
	@${REINPLACE_CMD} -e 's|Create(char\*|Create(const char* |g' ${WRKSRC}/Texture.*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glxs ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/*.raw ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ReadMe.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>

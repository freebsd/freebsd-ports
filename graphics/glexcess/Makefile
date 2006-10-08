# New ports collection makefile for:	glexcess
# Date created:			1 September 2006
# Whom:				Hernan Di Pietro <hernan.di.pietro@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	glexcess
PORTVERSION=	1.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.glexcess.com/files/
DISTNAME=	${PORTNAME}

MAINTAINER=	hernan.di.pietro@gmail.com
COMMENT=	An impressive OpenGL Demo

LIB_DEPENDS=	glut:${PORTSDIR}/graphics/libglut

USE_X_PREFIX=	yes
USE_GL=		yes

MAKE_ARGS=	'CXXFLAGS=${CXXFLAGS} -I${X11BASE}/include -pipe -s -O2' \
		'LDFLAGS=-L${X11BASE}/lib -lGL -lglut'

post-patch:
	@${REINPLACE_CMD} -e 's|data/|${DATADIR}/|' ${WRKSRC}/scene*.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glxs ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/*.raw ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ReadMe.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>

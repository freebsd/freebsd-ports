# New ports collection makefile for:	threeDS
# Date created:				5 December 2000
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	threeDS
PORTVERSION=	0.3.1
CATEGORIES=	graphics python
MASTER_SITES=	http://www.demonseed.net/~jp/code/threeDS/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Python module and viewer for loading and displaying models in 3DS format

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/OpenGL/__init__.py:${PORTSDIR}/graphics/py-opengl

USE_PYTHON=	yes

do-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -l ${WRKSRC}

do-install:
	${MKDIR} ${PREFIX}/share/threeDS
	${MKDIR} ${PREFIX}/lib/${PYTHON_VERSION}/site-packages
	${RM} -f ${WRKSRC}/*.orig
	${INSTALL_DATA} ${WRKSRC}/threeDS.py* ${PREFIX}/lib/${PYTHON_VERSION}/site-packages
	${INSTALL_SCRIPT} ${WRKSRC}/view3ds.py* ${PREFIX}/share/threeDS
	${LN} -sf ${PREFIX}/share/threeDS/view3ds.py ${PREFIX}/bin/view3ds

.include <bsd.port.mk>

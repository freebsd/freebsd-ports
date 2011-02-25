# New ports collection makefile for:	py-amanith
# Date created:		2006-09-01
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	amanith
PORTVERSION=	0.3.35
PORTREVISION=	5
CATEGORIES=	graphics python
MASTER_SITES=	http://muksuluuri.ath.cx/~skyostil/projects/pyamanith/dist/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyAmanith-${PORTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Python wrapper for the amanith 2D vector graphics library

LIB_DEPENDS=	amanith.1:${PORTSDIR}/graphics/amanith
BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13

USE_GL=		glew
USE_PYTHON=	2.5+
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	PyAmanith

post-patch:
	${REINPLACE_CMD} -i "" -e 's|^swig-cpp.*|swig-opts = -c++|g' ${WRKSRC}/setup.cfg

.include <bsd.port.mk>

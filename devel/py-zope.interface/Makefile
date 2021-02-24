# Created by: Neal Nelson <neal@nelson.name>
# $FreeBSD$

PORTNAME=	zope.interface
PORTVERSION=	5.2.0
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Interfaces for Python

LICENSE=	ZPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/zope/interface/_zope_interface_coptimizations*.so

.include <bsd.port.mk>

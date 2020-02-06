# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	odfpy
PORTVERSION=	1.4.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP \
		http://opendocumentfellowship.com/files/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python API and Tools to Manipulate OpenDocument Files

LICENSE=	APACHE20 GPLv2
LICENSE_COMB=	dual

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}defusedxml>0:devel/py-defusedxml@${PY_FLAVOR}

CONFLICTS_BUILD=	py${PYTHON_SUFFIX}-setuptools_scm

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

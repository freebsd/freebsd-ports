PORTNAME=	odfpy
PORTVERSION=	1.4.1
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		http://opendocumentfellowship.com/files/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python API and Tools to Manipulate OpenDocument Files
WWW=		https://github.com/eea/odfpy

LICENSE=	APACHE20 GPLv2
LICENSE_COMB=	dual

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}defusedxml>0:devel/py-defusedxml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>

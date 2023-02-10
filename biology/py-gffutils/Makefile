PORTNAME=	gffutils
DISTVERSION=	0.11.0
CATEGORIES=	biology python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Work with GFF and GTF files in a flexible database framework
WWW=		https://github.com/daler/gffutils

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argcomplete>=1.9.4:devel/py-argcomplete@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}argh>=0.26.2:devel/py-argh@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyfaidx>=0.5.5.2:biology/py-pyfaidx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplejson>0:devel/py-simplejson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.12.0:devel/py-six@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes

.include <bsd.port.mk>

PORTNAME=	xcaplib
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://download.ag-projects.com/XCAP/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python XCAP client library

LICENSE=	LGPL20+

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-application>=1.1.5:devel/py-python-application@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=0:devel/py-twisted@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>

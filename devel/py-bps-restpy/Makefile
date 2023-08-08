PORTNAME=	bps_restpy
PORTVERSION=	9.0.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	BreakingPoint REST API Python Wraper
WWW=		https://pypi.org/project/bps-restpy/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>

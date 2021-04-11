# Created by: Wen Heping <wenheping@gmail.com>

PORTNAME=	rpyc
PORTVERSION=	5.0.1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skozlov@FreeBSD.org
COMMENT=	Remote Python Call

LICENSE=	MIT

USES=		python:3.6+

USE_GITHUB=	yes
GH_ACCOUNT=	tomerfiliba-org

OPTIONS_DEFINE=	PLUMBUM
OPTIONS_DEFAULT=PLUMBUM

PLUMBUM_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plumbum>0:sysutils/py-plumbum@${PY_FLAVOR}
PLUMBUM_DESC=	Required for features like rpyc_classic.py and zero deploy

NO_ARCH=	yes
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>

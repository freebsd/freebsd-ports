PORTNAME=	rpyc
PORTVERSION=	5.1.0
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skozlov@FreeBSD.org
COMMENT=	Remote Python Call

LICENSE=	MIT

USES=		cpe python:3.6+
CPE_VENDOR=	${PORTNAME:tl}_project

USE_GITHUB=	yes
GH_ACCOUNT=	tomerfiliba-org

OPTIONS_DEFINE=	PLUMBUM
OPTIONS_DEFAULT=PLUMBUM

PLUMBUM_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plumbum>0:sysutils/py-plumbum@${PY_FLAVOR}
PLUMBUM_DESC=	Required for features like rpyc_classic.py and zero deploy

NO_ARCH=	yes
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>

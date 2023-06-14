PORTNAME=	rpyc
PORTVERSION=	5.3.1
PORTREVISION=	1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skozlov@FreeBSD.org
COMMENT=	Remote Python Call
WWW=		https://rpyc.readthedocs.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}

USES=		cpe python shebangfix
CPE_VENDOR=	${PORTNAME:tl}_project

SHEBANG_FILES=	rpyc/cli/*.py

USE_GITHUB=	yes
GH_ACCOUNT=	tomerfiliba-org

OPTIONS_DEFINE=	PLUMBUM
OPTIONS_DEFAULT=PLUMBUM

PLUMBUM_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plumbum>0:sysutils/py-plumbum@${PY_FLAVOR}
PLUMBUM_DESC=	Required for features like rpyc_classic.py and zero deploy

NO_ARCH=	yes
USE_PYTHON=	autoplist pep517

.include <bsd.port.mk>

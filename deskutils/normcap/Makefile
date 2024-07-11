PORTNAME=	normcap
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.8
CATEGORIES=	deskutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OCR powered screen-capture tool
WWW=		https://dynobo.github.io/normcap/

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>=2.12.1:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}retry2>=0.9.5:devel/py-retry2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rope>=1.7.0:devel/py-rope@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>=0.10.2:textproc/py-toml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-retry>=0.9.9.4:devel/py-types-retry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-toml>=0.10.8.1:devel/py-types-toml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.4.0:devel/py-typing-extensions@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jeepney>=0.8.0:devel/py-jeepney@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyside6>0:devel/pyside6@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shiboken6>=6.6.1:devel/shiboken6@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 noflavors autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	dynobo

NO_ARCH=	yes

.include <bsd.port.mk>

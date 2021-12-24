PORTNAME=	knock
DISTVERSION=	5.2.0
CATEGORIES=	dns
PKGNAMESUFFIX=	py

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool designed to enumerate subdomains on a target domain

LICENSE=	GPLv2

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>0:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python pyqt:5 # pyqt:5 isn't used: https://github.com/guelfoweb/knock/issues/108
USE_PYTHON=	distutils noflavors autoplist
USE_PYQT=	core_run

USE_GITHUB=	yes
GH_ACCOUNT=	guelfoweb

NO_ARCH=	yes

.include <bsd.port.mk>

PORTNAME=	knock
DISTVERSION=	9.0.0
CATEGORIES=	dns
PKGNAMESUFFIX=	py

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool designed to enumerate subdomains on a target domain
WWW=		https://github.com/guelfoweb/knock

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dnspython>=2.8.0:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.28.1:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyopenssl>0:security/py-pyopenssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>=1.0.1:www/py-python-dotenv@${PY_FLAVOR}

USES=		python pyqt:5 # pyqt:5 isn't used: https://github.com/guelfoweb/knock/issues/108
USE_PYTHON=	distutils noflavors autoplist
USE_PYQT=	pyqt5:run

USE_GITHUB=	yes
GH_ACCOUNT=	guelfoweb

WRKSRC=		${WRKDIR}/${PORTNAME}py-${DISTVERSION}

NO_ARCH=	yes

.include <bsd.port.mk>

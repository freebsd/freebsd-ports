PORTNAME=	pydbus
DISTVERSION=	0.6.0
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Pythonic DBus library
WWW=		https://github.com/LEW21/pydbus/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
USES=		gnome python
USE_GNOME=	pygobject3:run
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>

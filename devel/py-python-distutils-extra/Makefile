PORTNAME=	python-distutils-extra
PORTVERSION=	3.2
CATEGORIES=	devel python
MASTER_SITES=	DEBIAN
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-distutils-extra_${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Add support for i18n, documentation, and icons to distutils
WWW=		https://salsa.debian.org/python-team/packages/python-distutils-extra

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python tar:xz
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes
WRKSRC=		${WRKDIR}/python-distutils-extra

.include <bsd.port.mk>

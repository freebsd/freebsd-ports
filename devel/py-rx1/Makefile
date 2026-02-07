PORTNAME=	rx
PORTVERSION=	1.6.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	1
DISTNAME=	Rx-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Reactive Extensions (Rx) for Python
WWW=		https://github.com/ReactiveX/RxPY

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

# rx 3.0.0+ requires Python 3.6+
PORTSCOUT=	limit:^1\.

.include <bsd.port.mk>

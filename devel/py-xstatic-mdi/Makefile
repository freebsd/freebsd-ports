PORTNAME=	xstatic-mdi
PORTVERSION=	1.6.50.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	xstatic_mdi-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	mdi (Material Design Icons) ${PORTVERSION:R} (XStatic packaging standard)
WWW=		https://opendev.org/openstack/xstatic-mdi \
		https://github.com/openstack/xstatic-mdi

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>

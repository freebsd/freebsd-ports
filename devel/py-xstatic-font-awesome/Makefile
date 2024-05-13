PORTNAME=	xstatic-font-awesome
PORTVERSION=	6.2.1.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-Font-Awesome-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Iconic font and CSS framework (font-awesome)
WWW=		https://fontawesome.com/ \
		https://github.com/xstatic-py/xstatic-font-awesome

LICENSE=	OFL11

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>

PORTNAME=	types-Flask-Cors
PORTVERSION=	6.0.0.20250809
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g:tl}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Typing stubs for Flask-Cors
WWW=		https://github.com/python/typeshed

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>0:www/py-flask@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>

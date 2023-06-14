PORTNAME=	behave
PORTVERSION=	1.2.6
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Behaviour-driven development in Python style
WWW=		https://github.com/behave/behave

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}parse>=1.8.2:textproc/py-parse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parse-type>=0.4.2:textproc/py-parse-type@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.11:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>

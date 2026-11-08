PORTNAME=	pypugjs
PORTVERSION=	7.0.0
CATEGORIES=	devel lang python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PugJS syntax adapter for Django, Jinja2 and Mako templates
WWW=		https://github.com/kakulukia/pypugjs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}charset-normalizer>=3.4.9<4:textproc/py-charset-normalizer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.17.0<2:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>

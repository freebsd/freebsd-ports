PORTNAME=	xstatic-term.js
PORTVERSION=	0.0.7.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	xstatic_term_js-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	term.js ${PORTVERSION:R} (XStatic packaging standard)
WWW=		https://github.com/takluyver/XStatic-termjs

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>

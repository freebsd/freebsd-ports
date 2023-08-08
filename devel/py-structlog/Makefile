PORTNAME=	structlog
PORTVERSION=	18.2.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Structured Logging for Python
WWW=		https://www.structlog.org/

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.apache2
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE.mit

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>=0.3.3:devel/py-colorama@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

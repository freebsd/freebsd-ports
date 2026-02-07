PORTNAME=	ordered-set
PORTVERSION=	4.1.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	MutableSet that remembers its order, so that every entry has an index
WWW=		https://github.com/rspeer/ordered-set

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.2<4:devel/py-flit-core@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist pep517 pytest

.include <bsd.port.mk>

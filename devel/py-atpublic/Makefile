PORTNAME=	atpublic
PORTVERSION=	5.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Very simple decorator and function of module's all
WWW=		https://public.readthedocs.io/

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

MAKE_ENV=	ATPUBLIC_BUILD_EXTENSION=1
NO_ARCH=	yes

post-extract:
	${CP} ${FILESDIR}/setup* ${WRKSRC}

.include <bsd.port.mk>

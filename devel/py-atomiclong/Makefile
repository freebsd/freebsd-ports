PORTNAME=	atomiclong
PORTVERSION=	0.1.1
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	AtomicLong type using CFFI
WWW=		https://pypi.org/project/atomiclong/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils pytest

post-patch:
	@${REINPLACE_CMD} '/setup_requires/d' ${WRKSRC}/${PYSETUP}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_cffi__*.so

.include <bsd.port.mk>

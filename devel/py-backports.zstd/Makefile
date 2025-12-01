PORTNAME=	backports.zstd
PORTVERSION=	1.1.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	backports_zstd-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Backport of compression.zstd
WWW=		https://github.com/Rogdham/backports.zstd

LICENSE=	PSFL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		localbase:ldflags python
USE_PYTHON=	autoplist concurrent pep517

LDFLAGS+=	-lzstd

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/src/c/zstd/lib/

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>

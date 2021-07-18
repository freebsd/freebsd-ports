PORTNAME=	zstd
DISTVERSION=	1.5.0.2
CATEGORIES=	archivers python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python binding for Zstandard compression library

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		python:3.6+ localbase
USE_PYTHON=	distutils autoplist
PYDISTUTILS_BUILDARGS=	--external

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/zstd*.so

.include <bsd.port.mk>

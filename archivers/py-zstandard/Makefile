# $FreeBSD$

PORTNAME=	zstandard
DISTVERSION=	0.8.2
CATEGORIES=	archivers python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Zstandard bindings for Python, a full-featured version

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.8.0:devel/py-cffi@${FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
#PYDISTUTILS_BUILDARGS=	--system-zstd  # The next release is going to allow to unbind zstd

post-install:
	@cd ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} && ${STRIP_CMD} zstd.so _zstd_cffi.so

.include <bsd.port.mk>

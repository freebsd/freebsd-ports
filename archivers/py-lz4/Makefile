# $FreeBSD$

PORTNAME=	lz4
PORTVERSION=	0.9.0
CATEGORIES=	archivers python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python binding for the LZ4 compression library

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm
LIB_DEPENDS=	liblz4.so:archivers/liblz4

USE_PYTHON=	distutils
USES=		python pkgconfig

CFLAGS+=  -I${LOCALBASE}/include

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/_version.so \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/block/_block.so \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/frame/_frame.so

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	lz4
PORTVERSION=	0.12.0
CATEGORIES=	archivers python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python binding for the LZ4 compression library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>=0:devel/py-pytest-runner@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${FLAVOR}
LIB_DEPENDS=	liblz4.so:archivers/liblz4
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${FLAVOR}

USE_PYTHON=	distutils py3kplist
USES=		pkgconfig python

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/_version.so \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/block/_block.so \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/frame/_frame.so

.include <bsd.port.mk>

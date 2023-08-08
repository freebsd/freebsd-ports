PORTNAME=	reedsolo
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.0
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	loader@FreeBSD.org
COMMENT=	Pure-Python Reed Solomon encoder/decoder
WWW=		https://github.com/tomerfiliba/reedsolomon

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist cython distutils pytest

GH_ACCOUNT=	tomerfiliba
GH_PROJECT=	reedsolomon
TEST_ENV+=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

# PR 267882: regenerate creedsolo.c with Cython
post-patch:
	@${RM} ${WRKSRC}/creedsolo.c

.include <bsd.port.mk>

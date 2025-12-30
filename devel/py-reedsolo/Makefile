PORTNAME=	reedsolo
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.5
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	loader@FreeBSD.org
COMMENT=	Pure-Python Reed Solomon encoder/decoder
WWW=		https://github.com/tomerfiliba-org/reedsolomon

LICENSE=	MIT0 UNLICENSE
LICENSE_COMB=	dual
LICENSE_NAME_MIT0=	MIT-0 License
LICENSE_FILE_MIT0=	${WRKSRC}/LICENSE
LICENSE_FILE_UNLICENSE=	${WRKSRC}/LICENSE
LICENSE_PERMS_MIT0=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	tomerfiliba-org
GH_PROJECT=	reedsolomon
USE_PYTHON=	autoplist cython3 distutils pytest

TEST_ENV+=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

# PR 267882: regenerate creedsolo.c with Cython
post-patch:
	@${RM} ${WRKSRC}/creedsolo.c

.include <bsd.port.mk>

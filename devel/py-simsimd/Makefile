PORTNAME=	simsimd
DISTVERSION=	6.0.4
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Portable mixed-precision BLAS-like vector math library for x86 and ARM
WWW=		https://ashvardanian.com/posts/simsimd-faster-scipy/ \
		https://github.com/ashvardanian/simsimd

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 i386

USES=		python
USE_PYTHON=	distutils autoplist

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/simsimd${PYTHON_TAG}.so

.include <bsd.port.mk>

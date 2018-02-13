# $FreeBSD$

PORTNAME=	SoundFile
DISTVERSION=	0.9.0
DISTVERSIONSUFFIX=	.post1
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Audio library based on libsndfile, CFFI and NumPy

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=0.6:devel/py-cffi@${FLAVOR} \
		${PYNUMPY} \
		${PREFIX}/lib/libsndfile.so:audio/libsndfile

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>

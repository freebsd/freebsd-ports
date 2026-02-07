PORTNAME=	SoundFile
DISTVERSION=	0.13.1
CATEGORIES=	audio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tl}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Audio library based on libsndfile, CFFI and NumPy
WWW=		https://github.com/bastibe/PySoundFile

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.0:devel/py-cffi@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.0:devel/py-cffi@${PY_FLAVOR} \
		${PYNUMPY} \
		${PREFIX}/lib/libsndfile.so:audio/libsndfile

USES=		python
USE_PYTHON=	distutils autoplist pytest # pkg-plist has files that are missing in autoplist

NO_ARCH=	yes

.include <bsd.port.mk>

PORTNAME=	py2bit
DISTVERSION=	1.0.1
CATEGORIES=	biology python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Python interface for 2bit packed nucleotide files
WWW=		https://github.com/deeptools/py2bit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python
# Can't switch to pep517 yet: Requires setuptools>=74.1
USE_PYTHON=	autoplist distutils

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/py2bit.cpython-311.so

.include <bsd.port.mk>

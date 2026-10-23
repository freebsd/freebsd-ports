PORTNAME=	pyminizip
DISTVERSION=	0.2.6
PORTREVISION=	2
CATEGORIES=	archivers python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Library to create a password encrypted zip file in python
WWW=		https://github.com/smihica/pyminizip

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USES=		python
USE_PYTHON=	distutils concurrent autoplist

post-install:
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} -name '*.so' \
		-exec ${STRIP_CMD} {} +

.include <bsd.port.mk>

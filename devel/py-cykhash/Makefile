PORTNAME=	cykhash
DISTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Cython equivalent to khash-sets/maps
WWW=		https://pypi.python.org/project/cykhash/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist cython distutils

post-stage:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/cykhash/*.so

.include <bsd.port.mk>

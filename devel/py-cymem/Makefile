PORTNAME=	cymem
PORTVERSION=	2.0.6
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cython memory helper
WWW=		https://github.com/explosion/cymem

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+
USE_PYTHON=	distutils cython autoplist

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/cymem/cymem*.so

.include <bsd.port.mk>

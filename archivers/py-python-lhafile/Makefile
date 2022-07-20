PORTNAME=	python-lhafile
DISTVERSION=	0.2.2
CATEGORIES=	archivers python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	lhafile-${DISTVERSION}

MAINTAINER=	cs@innolan.dk
COMMENT=	LHA(.lzh) file extract interface

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/lzhlib*.so

.include <bsd.port.mk>

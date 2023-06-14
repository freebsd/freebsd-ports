PORTNAME=	amalgamate
PORTVERSION=	0.1.3
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Collapse Python packages into a single module
WWW=		https://github.com/xonsh/amalgamate

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist distutils concurrent

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%DOCSDIR%%|${DOCSDIR}|' ${WRKSRC}/setup.py

.include <bsd.port.mk>

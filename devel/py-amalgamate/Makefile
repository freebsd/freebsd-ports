PORTNAME=	amalgamate
PORTVERSION=	0.1.3
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Collapse Python packages into a single module

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.4+
USE_PYTHON=	autoplist distutils concurrent

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%DOCSDIR%%|${DOCSDIR}|' ${WRKSRC}/setup.py

.include <bsd.port.mk>

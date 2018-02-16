# Created by: Carlos J. Puga Medina <cpm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	codesearch-py
PORTVERSION=	0.1
PORTREVISION=	3
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	Python library for accessing Chromium CodeSearch

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist concurrent distutils

USE_GITHUB=	yes
GH_ACCOUNT=	chromium
GH_TAGNAME=	df9f4df

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m unittest discover -v

.include <bsd.port.mk>

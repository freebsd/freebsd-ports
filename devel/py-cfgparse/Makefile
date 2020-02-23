# Created by: John Ferrell
# $FreeBSD$

PORTNAME=	cfgparse
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jdferrell3@yahoo.com
COMMENT=	Python module for parsing configuration files

LICENSE=	MIT

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

USES=		dos2unix python:2.7 zip
DOS2UNIX_FILES=	cfgparse.py
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

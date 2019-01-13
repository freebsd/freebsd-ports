# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pglast
PORTVERSION=	1.1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	a.wolk@fudosecurity.com
COMMENT=	PostgreSQL Languages AST and statements prettifier

LICENSE=	GPLv3+
#LICENSE_FILE=	${WRKSRC}/

USES=		gmake python:3.4+
USE_PYTHON=	autoplist distutils

post-patch:
	@${REINPLACE_CMD} -e 's|make|gmake|' ${WRKSRC}/setup.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pglast/parser.so

.include <bsd.port.mk>

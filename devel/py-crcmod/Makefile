# New ports collection makefile for:	crcmod
# Date created:				19 Sep 2010
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	crcmod
PORTVERSION=	1.7
CATEGORIES=	devel python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Module for Cyclic Redundancy Check (CRC) calculations

LICENSE=	MIT

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/changelog ${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} html ${DOCSDIR}
.endif

.include <bsd.port.mk>

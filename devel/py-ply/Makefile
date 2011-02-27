# ex:ts=8
# New ports collection makefile for:	ply
# Date created:			Jul 31, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ply
PORTVERSION=	3.4
CATEGORIES=	devel python
MASTER_SITES=	http://www.dabeaz.com/ply/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Python Lex-Yacc

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

PORTDOCS=	ply.html internal.html README

pre-configure:
	@${REINPLACE_CMD} -e 's|from setuptools import setup|from distutils.core import setup|' \
		${WRKSRC}/setup.py

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/ply.html ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/internal.html ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/example/ ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>

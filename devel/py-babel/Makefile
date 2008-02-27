# New ports collection makefile for:	py-babel
# Date created:		7 July 2007
# Whom:			Dryice Liu	<dryice@dryice.name>
#
# $FreeBSD$
#

PORTNAME=	Babel
PORTVERSION=	0.9.2
CATEGORIES=	devel python
MASTER_SITES=	http://ftp.edgewall.com/pub/babel/ \
		${MASTER_SITE_LOCAL} \
		http://dryice.name/computer/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	dryice
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dryice@FreeBSD.org
COMMENT=	A collection of tools for internationalizing Python applications

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	easy_install

.if !defined(NOPORTDOCS)
PORTDOCS=	doc/*
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for docfile in ${PORTDOCS}
	${CP} -r ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

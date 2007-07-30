# New ports collection makefile for:	py-durus
# Date created:		13 Nov 2006
# Whom:	      		Dryice Liu <dryice@dryice.name>
#
# $FreeBSD$
#

PORTNAME=	durus
PORTVERSION=	3.7
CATEGORIES=	devel python
MASTER_SITES=	http://www.mems-exchange.org/software/durus/ \
		${MASTER_SITE_LOCAL} \
		http://dryice.name/computer/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	dryice
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Durus-${PORTVERSION}

MAINTAINER=	dryice@FreeBSD.org
COMMENT=	A persistent object storage system for Python

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Durus
MAN1=	durus.1

.include <bsd.port.pre.mk>

post-install:
	@ ${INSTALL_MAN} ${WRKSRC}/doc/durus.1 ${MANPREFIX}/man/man1

.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for docfile in ACKS.txt CHANGES.txt history.py INSTALL.txt LICENSE.txt README.txt doc/FAQ.txt
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>

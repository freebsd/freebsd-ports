# New ports collection makefile for:	py-durus
# Date created:		13 Nov 2006
# Whom:	      		Dryice Liu <dryice@dryice.name>
#
# $FreeBSD$
#

PORTNAME=	durus
PORTVERSION=	3.8
CATEGORIES=	devel python
MASTER_SITES=	http://www.mems-exchange.org/software/durus/ \
		${MASTER_SITE_LOCAL} \
		http://dryice.name/computer/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	dryice
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Durus-${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	A persistent object storage system for Python

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes
PYDISTUTILS_PKGNAME=	Durus

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for docfile in ACKS.txt CHANGES.txt INSTALL.txt LICENSE.txt README.txt doc/FAQ.txt
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>

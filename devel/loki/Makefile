# New ports collection makefile for:	loki
# Date created:		5 Feb 2006
# Whom:			Sun Chang-Ming
#
# $FreeBSD$
#

PORTNAME=	loki
PORTVERSION=	0.1.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	loki-lib

MAINTAINER=	snnn119@gmail.com
COMMENT=	A C++ library of common design patterns

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GCC=	3.4+

DOCS=		README CHANGES doc/html/* doc/flex/* doc/yasli/*

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/html
	${MKDIR} ${DOCSDIR}/flex
	${MKDIR} ${DOCSDIR}/yasli
.for i in ${DOCS}
	${INSTALL_MAN} ${WRKSRC}/${i} ${DOCSDIR}/${i%/.*}
.endfor
.endif

.include <bsd.port.mk>

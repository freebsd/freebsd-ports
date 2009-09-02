# New ports collection makefile for:	loki
# Date created:		5 Feb 2006
# Whom:			Sun Chang-Ming
#
# $FreeBSD$
#

PORTNAME=	loki
PORTVERSION=	0.1.5
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}-lib/Loki/Loki%20${PORTVERSION}

MAINTAINER=	snnn119@gmail.com
COMMENT=	A C++ library of common design patterns

USE_DOS2UNIX=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

DOCS=		README CHANGES doc/flex/flex_string.html \
		doc/yasli/Notes.txt \
		doc/yasli/yasli.html

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_MAN} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

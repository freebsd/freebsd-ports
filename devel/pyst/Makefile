# New ports collection makefile for:    pyst
# Date created:         06 Sep 2011
# Whom:                 Mikhail T. <m.tsatsenko@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pyst
PORTVERSION=	0.3.22
CATEGORIES=	devel python
MASTER_SITES=	SF/${PORTNAME}/pyst/${PORTVERSION}

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	Python interface to allow Asterisk programming

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

DOCS=	README README.html ChangeLog

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

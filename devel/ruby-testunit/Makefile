# New ports collection makefile for:	Lapidary
# Date created:		22 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	lapidary
PORTVERSION=	0.2.0
CATEGORIES=	devel ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes

WRKSRC=		${WRKDIR}/${MODULE_NAME}
NO_BUILD=	yes

MODULE_NAME=	Lapidary
DOCS_EN=	README	*.html

do-install:
	${MKDIR} ${RUBY_SITELIBDIR}/${MODULE_NAME}
	${CP} -R ${WRKSRC}/*.rb ${WRKSRC}/UI ${RUBY_SITELIBDIR}/${MODULE_NAME}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>

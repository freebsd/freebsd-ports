# New ports collection makefile for:	GraphR
# Date created:		24 October 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	graph
PORTVERSION=	0.1.4
CATEGORIES=	graphics ruby
MASTER_SITES=	http://rockit.sourceforge.net/subprojects/graphr/
MASTER_SITE_SUBDIR=	knu
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}r-${PORTVERSION:S/./-/g}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/bin/dot:${PORTSDIR}/graphics/graphviz

USE_RUBY=	yes

NO_BUILD=	yes

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_DOCDIR}/${PORTNAME}/
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	NodeDump for Ruby
# Date created:		10 November 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	nodedump
PORTVERSION=	0.1.7
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.pragmaticprogrammer.com/ruby/downloads/files/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	nodeDump-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_MODDOCDIR}/
.endif

.include <bsd.port.mk>

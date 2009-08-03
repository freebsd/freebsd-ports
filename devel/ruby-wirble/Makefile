# New ports collection makefile for:	ruby-lafcadio
# Date created:		09 Jan 2007
# Whom:			Christopher Boumenot <boumenot@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	wirble
PORTVERSION=	0.1.2
CATEGORIES=	devel ruby
MASTER_SITES=http://pablotron.org/files/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A set of enhancements of irb

DOCS_EN=	README

USE_RUBY=	yes

do-build:

do-install:
	${INSTALL_DATA} ${WRKSRC}/wirble.rb ${RUBY_SITELIBDIR}/

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	Data-Visitor
# Date created:		26 Mar 2006
# Whom:			Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Data-Visitor
PORTVERSION=	0.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Visitor style traversal of Perl data structures

BUILD_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=	Data::Visitor.3 \
	Data::Visitor::Callback.3

post-extract:
	@${PERL} -i.bak -ne 'print unless /Test::/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>

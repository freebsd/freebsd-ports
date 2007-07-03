# New ports collection makefile for:	devel/p5-Class-Accessor-Grouped
# Date created:				Jun 18, 2007
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-Accessor-Grouped
PORTVERSION=	0.07000
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Lets you build groups of accessors

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-Class-Inspector>=0:${PORTSDIR}/devel/p5-Class-Inspector

PERL_CONFIGURE=	yes

MAN3=	Class::Accessor::Grouped.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500800
IGNORE=	requires perl 5.8.0 or later. Install lang/perl5.8 and try again
.endif
.include <bsd.port.post.mk>

# New ports collection makefile for:	Class-C3-XS
# Date created:	   25 May 2007
# Whom:		   Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-C3-XS
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	XS speedups for Class::C3

PERL_CONFIGURE=	yes

MAN3=		Class::C3::XS.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800	# Inherited from devel/p5-Algorithm-C3
IGNORE=		requires perl 5.8.x or later, install lang/perl5.8
.endif

.include <bsd.port.post.mk>

# Ports collection Makefile for:		p5-Object-MultiType
# Date created:					Oct 10 2003
# Whom:						clsung@dragon2.net
#
# $FreeBSD$

PORTNAME=	Object-MultiType
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Object
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl Objects as Hash, Array and Scalar at the same time

MAN3=		Object::MultiType.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		Port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>

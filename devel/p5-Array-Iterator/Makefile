# New ports collection makefile for:	Array Iterator
# Date created:				1 August 2004
# Whom:					Aaron Dalton <aaron@daltons.ca>
#
# $FreeBSD$
#

PORTNAME=	Array-Iterator
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Array
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@daltons.ca
COMMENT=	A set of array iterators

MAN3=		Array::Iterator.3 Array::Iterator::Circular.3 \
       		Array::Iterator::BiDirectional.3 Array::Iterator::Reusable.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		"This port requires perl 5.6 or above."
.endif

.include <bsd.port.post.mk>

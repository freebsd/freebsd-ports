# New ports collection makefile for:	p5-Heap
# Date created:				6 April 2001
# Whom:					Anatoliy Dmytriyev
#
# $FreeBSD$
#

PORTNAME=	Heap
PORTVERSION=	0.50
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Heap
PKGNAMEPREFIX=	p5-

MAINTAINER=	tolid@plab.ku.dk

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Heap.3 Heap::Binary.3 Heap::Binomial.3 Heap::Elem::Num.3 \
		Heap::Elem::NumRev.3 Heap::Elem::Ref.3 Heap::Elem::RefRev.3 \
		Heap::Elem::Str.3 Heap::Elem::StrRev.3 Heap::Elem.3 \
		Heap::Fibonacci.3

.include <bsd.port.mk>

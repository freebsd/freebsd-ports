# New ports collection makefile for:	p5-Heap-Simple-XS
# Date created:				11 November 2004
# Whom:					Aaron Dalton <aaron@daltons.ca>
#
# $FreeBSD$
#

PORTNAME=	Heap-Simple-XS
PORTVERSION=	0.09
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Heap
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	An XS implementation of the Heap::Simple interface

BUILD_DEPENDS=	${SITE_PERL}/Heap/Simple.pm:${PORTSDIR}/devel/p5-Heap-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Heap::Simple::XS.3

.include <bsd.port.mk>

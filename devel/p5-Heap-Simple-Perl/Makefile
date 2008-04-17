# New ports collection makefile for:	p5-Heap-Simple-Perl
# Date created:				11 November 2004
# Whom:					Aaron Dalton <aaron@daltons.ca>
#
# $FreeBSD$
#

PORTNAME=	Heap-Simple-Perl
PORTVERSION=	0.14
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	A pure perl implementation of the Heap::Simple interface

BUILD_DEPENDS=	${SITE_PERL}/Heap/Simple.pm:${PORTSDIR}/devel/p5-Heap-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+
CONFIGURE_ARGS+=	-n

MAN3=		Heap::Simple::Perl.3

.include <bsd.port.mk>

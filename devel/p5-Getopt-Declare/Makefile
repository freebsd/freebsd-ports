# New ports collection makefile for:	devel/p5-Getopt-Declare
# Date created:				16 Sep 2001
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Getopt-Declare
PORTVERSION=	1.12
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Declaratively Expressed Command-Line Arguments via Regular Expressions

BUILD_DEPENDS=	p5-Text-Balanced>=0:${PORTSDIR}/textproc/p5-Text-Balanced
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Getopt::Declare.3

.include <bsd.port.mk>

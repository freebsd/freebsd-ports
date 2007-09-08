# New ports collection makefile for:	devel/p5-Test-Data
# Date created:				18 March 2006
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Data
PORTVERSION=	1.20
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/B/BD/BDFOY
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Test functions for particular variable types

RUN_DEPENDS=	p5-Scalar-List-Utils>0:${PORTSDIR}/lang/p5-Scalar-List-Utils
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Test::Data.3 \
		Test::Data::Array.3 \
		Test::Data::Function.3 \
		Test::Data::Hash.3 \
		Test::Data::Scalar.3

.include <bsd.port.mk>

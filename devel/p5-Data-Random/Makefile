# New Ports Collection Makefile for:	p5-Data-Random
# Date created:				2004-07-07
# Whom:					Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Data-Random
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Data
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for generating random data

.include <bsd.port.pre.mk>

# define WITHOUT_DATE_CALC to disable support for rand_date()
.if !defined(WITHOUT_DATE_CALC)
EXTRA_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc
.endif

# define WITH_GD to enable support for rand_image()
.if defined(WITH_GD)
EXTRA_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD
.endif

BUILD_DEPENDS+=	${EXTRA_DEPENDS}
RUN_DEPENDS+=	${EXTRA_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Data::Random.3 Data::Random::WordList.3

.include <bsd.port.post.mk>

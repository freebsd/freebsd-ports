# New ports collection makefile for:    p5-Data-Dumper-Concise
# Date created:         2009-11-24
# Whom:                 Christopher Key <cjk32@cam.ac.uk>
#
# $FreeBSD$
#

PORTNAME=	Data-Dumper-Concise
PORTVERSION=	2.020
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FREW
PKGNAMEPREFIX=	p5-

MAINTAINER=	cjk32@cam.ac.uk
COMMENT=	Less indentation and newlines plus sub deparsing

BUILD_DEPENDS=	p5-Data-Dumper>=0:${PORTSDIR}/devel/p5-Data-Dumper
RUN_DEPENDS=	p5-Data-Dumper>=0:${PORTSDIR}/devel/p5-Data-Dumper

TEST_DEPENDS =	p5-Error-Simple>=0:${PORTSDIR}/devel/p5-Error-Simple

OPTIONS=	ARGNAMES "Enable DwarnN subroutine" On

.include <bsd.port.options.mk>

.if defined(WITH_ARGNAMES)
BUILD_DEPENDS+=	p5-Devel-ArgNames>=0.03:${PORTSDIR}/devel/p5-Devel-ArgNames
RUN_DEPENDS+=	p5-Devel-ArgNames>=0.03:${PORTSDIR}/devel/p5-Devel-ArgNames
.endif

PERL_CONFIGURE=	yes

MAN3=		Data::Dumper::Concise.3 \
		Data::Dumper::Concise::Sugar.3 \
		Devel::Dwarn.3

.include <bsd.port.mk>

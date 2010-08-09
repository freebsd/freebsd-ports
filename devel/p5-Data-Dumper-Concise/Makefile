# New ports collection makefile for:    p5-Data-Dumper-Concise
# Date created:         2009-11-24
# Whom:                 Christopher Key <cjk32@cam.ac.uk>
#
# $FreeBSD$
#

PORTNAME=	Data-Dumper-Concise
PORTVERSION=	2.010
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cjk32@cam.ac.uk
COMMENT=	Less indentation and newlines plus sub deparsing

BUILD_DEPENDS=	p5-Devel-ArgNames>=0.03:${PORTSDIR}/devel/p5-Devel-ArgNames
RUN_DEPENDS=	p5-Devel-ArgNames>=0.03:${PORTSDIR}/devel/p5-Devel-ArgNames

PERL_CONFIGURE=	yes

MAN3=		Data::Dumper::Concise.3 \
		Data::Dumper::Concise::Sugar.3 \
		Devel::Dwarn.3

.include <bsd.port.mk>

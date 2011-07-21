# New ports collection makefile for:	FSA-Rules
# Date created:				11 Feb 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	FSA-Rules
PORTVERSION=	0.29
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DWHEELER
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Build simple rules-based state machines in Perl

RUN_DEPENDS=	p5-GraphViz>=2:${PORTSDIR}/graphics/p5-GraphViz \
		p5-Text-Tabs+Wrap>=0:${PORTSDIR}/textproc/p5-Text-Tabs+Wrap 

PERL_MODBUILD=	yes

MAN3=		FSA::Rules.3

.include <bsd.port.mk>

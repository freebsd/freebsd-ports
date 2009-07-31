# New ports collection makefile for:	FSA-Rules
# Date created:				11 Feb 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	FSA-Rules
PORTVERSION=	0.28
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/D/DW/DWHEELER
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Build simple rules-based state machines in Perl

RUN_DEPENDS=	${SITE_PERL}/GraphViz.pm:${PORTSDIR}/graphics/p5-GraphViz \
		${SITE_PERL}/Text/Wrap.pm:${PORTSDIR}/textproc/p5-Text-Tabs+Wrap
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		FSA::Rules.3

.include <bsd.port.mk>

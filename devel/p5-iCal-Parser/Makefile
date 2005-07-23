# New ports collection makefile for:	iCal::Parser
# Date created:		21 Apr 2005
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	iCal-Parser
PORTVERSION=	1.11
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/R/RF/RFRANKEL
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Parse iCalendar files into a data structure

BUILD_DEPENDS=	${SITE_PERL}/IO/String.pm:${PORTSDIR}/devel/p5-IO-String \
	${SITE_PERL}/FreezeThaw.pm:${PORTSDIR}/devel/p5-FreezeThaw \
	${SITE_PERL}/DateTime/Format/ICal.pm:${PORTSDIR}/devel/p5-DateTime-Format-ICal \
	${SITE_PERL}/Text/vFile/asData.pm:${PORTSDIR}/devel/p5-Text-vFile-asData
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
MAN3=		iCal::Parser.3

.include <bsd.port.mk>

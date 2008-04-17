# New ports collection makefile for:	iCal::Parser
# Date created:		21 Apr 2005
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	iCal-Parser
PORTVERSION=	1.14
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Parse iCalendar files into a data structure

BUILD_DEPENDS=	${SITE_PERL}/IO/String.pm:${PORTSDIR}/devel/p5-IO-String \
	p5-FreezeThaw>=0.43:${PORTSDIR}/devel/p5-FreezeThaw \
	p5-DateTime-Format-ICal>=0.08:${PORTSDIR}/devel/p5-DateTime-Format-ICal \
	p5-Text-vFile-asData>=0.02:${PORTSDIR}/devel/p5-Text-vFile-asData
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		iCal::Parser.3

.include <bsd.port.mk>

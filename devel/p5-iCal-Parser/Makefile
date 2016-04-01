# $FreeBSD$

PORTNAME=	iCal-Parser
PORTVERSION=	1.20
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Parse iCalendar files into a data structure

BUILD_DEPENDS=	p5-IO-String>=0:devel/p5-IO-String \
	p5-FreezeThaw>=0.43:devel/p5-FreezeThaw \
	p5-DateTime-Format-ICal>=0.08:devel/p5-DateTime-Format-ICal \
	p5-Text-vFile-asData>=0.02:devel/p5-Text-vFile-asData
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=	perl5
USE_PERL5=	configure

.include <bsd.port.mk>

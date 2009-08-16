# New ports collection makefile for:	p5-DateTime-Calendar-Christian
# Date created:	   26 june 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Calendar-Christian
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Dates in the Christian calendar

BUILD_DEPENDS=	${SITE_PERL}/DateTime/Calendar/Julian.pm:${PORTSDIR}/devel/p5-DateTime-Calendar-Julian
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		DateTime::Calendar::Christian.3

.include <bsd.port.mk>

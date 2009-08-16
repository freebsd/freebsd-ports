# New ports collection makefile for:	p5-DateTime-Event-ICal
# Date created:	   2 july 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Event-ICal
PORTVERSION=	0.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl DateTime extension for computing rfc2445 recurrences

BUILD_DEPENDS=	${SITE_PERL}/DateTime/Event/Recurrence.pm:${PORTSDIR}/devel/p5-DateTime-Event-Recurrence \
		${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		DateTime::Event::ICal.3

.include <bsd.port.mk>

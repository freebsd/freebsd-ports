# New ports collection makefile for:	POE-Component-Cron
# Date created:	   December 21 2010
# Whom:		   mat
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Cron
PORTVERSION=	0.021
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Schedule POE Events using a cron spec

BUILD_DEPENDS=	${SITE_PERL}/Test/Simple.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/POE/Component/Schedule.pm:${PORTSDIR}/devel/p5-POE-Component-Schedule \
		${SITE_PERL}/DateTime/Event/Random.pm:${PORTSDIR}/devel/p5-DateTime-Event-Random \
		${SITE_PERL}/DateTime/Event/Cron.pm:${PORTSDIR}/devel/p5-DateTime-Event-Cron
RUN_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/POE/Component/Schedule.pm:${PORTSDIR}/devel/p5-POE-Component-Schedule \
		${SITE_PERL}/DateTime/Event/Random.pm:${PORTSDIR}/devel/p5-DateTime-Event-Random \
		${SITE_PERL}/DateTime/Event/Cron.pm:${PORTSDIR}/devel/p5-DateTime-Event-Cron

PERL_CONFIGURE=	yes

MAN3=		POE::Component::Cron.3

.include <bsd.port.mk>

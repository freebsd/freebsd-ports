# New ports collection makefile for:	POE-Component-Schedule
# Date created:	   December 21 2010
# Whom:		   mat
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Schedule
PORTVERSION=	0.95
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Schedule POE Events using a cron spec

BUILD_DEPENDS=	${SITE_PERL}/Test/Simple.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/DateTime/Set.pm:${PORTSDIR}/devel/p5-DateTime-Set
RUN_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/DateTime/Set.pm:${PORTSDIR}/devel/p5-DateTime-Set

PERL_MODBUILD=	yes

MAN3=		POE::Component::Schedule.3

.include <bsd.port.mk>

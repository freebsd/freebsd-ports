# New ports collection makefile for:	p5-DateTime
# Date created:	   4 mai 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	DateTime
PORTVERSION=	0.16
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DateTime
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}01

MAINTAINER=	mat@FreeBSD.org
COMMENT=	A date and time object

RUN_DEPENDS=	${SITE_PERL}/Class/Factory/Util.pm:${PORTSDIR}/devel/p5-Class-Factory-Util \
		${SITE_PERL}/${PERL_ARCH}/Params/Validate.pm:${PORTSDIR}/devel/p5-Params-Validate \
		${SITE_PERL}/DateTime/TimeZone.pm:${PORTSDIR}/devel/p5-DateTime-TimeZone \
		${SITE_PERL}/DateTime/Locale.pm:${PORTSDIR}/devel/p5-DateTime-Locale \
		${SITE_PERL}/Time/Local.pm:${PORTSDIR}/devel/p5-Time-Local
BUILD_DEPENDS=	${RUN_DEPENDS} \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=		DateTime.3 DateTime::Duration.3 \
		DateTime::Infinite.3 DateTime::LeapSecond.3

.include <bsd.port.mk>

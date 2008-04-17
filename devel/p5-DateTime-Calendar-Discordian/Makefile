# New ports collection makefile for:	p5-DateTime-Calendar-Discordian
# Date created:				04 August 2006
# Whom:	      				Philip Paeps <philip@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Calendar-Discordian
PORTVERSION=	0.9.4
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	philip@FreeBSD.org
COMMENT=	Perl extension for the Discordian Calendar

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime \
		${SITE_PERL}/DateTime/Locale.pm:${PORTSDIR}/devel/p5-DateTime-Locale \
		${SITE_PERL}/${PERL_ARCH}/Params/Validate.pm:${PORTSDIR}/devel/p5-Params-Validate

PERL_CONFIGURE=	yes

MAN3=		DateTime::Calendar::Discordian.3

.include <bsd.port.mk>

# New ports collection makefile for:   p5-Date-ISO
# Date created:                13 May 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	Date-ISO
PORTVERSION=	1.30
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Date
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts dates between ISO and Gregorian formats

BUILD_DEPENDS=	${SITE_PERL}/Date/ICal.pm:${PORTSDIR}/devel/p5-Date-ICal \
		${SITE_PERL}/Date/Leapyear.pm:${PORTSDIR}/devel/p5-Date-Leapyear \
		${SITE_PERL}/Memoize.pm:${PORTSDIR}/devel/p5-Memoize
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Date::ISO.3

.include <bsd.port.mk>

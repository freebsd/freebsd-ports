# New ports collection makefile for:   p5-Date-ICal
# Date created:                12 May 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	Date-ICal
PORTVERSION=	1.69
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Date
PKGNAMEPREFIX=	p5-

MAINTAINER=	fuyuki@mj.0038.net

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Date/Leapyear.pm:${PORTSDIR}/devel/p5-Date-Leapyear

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Date::ICal.3 Date::ICal::Duration.3

.include <bsd.port.mk>

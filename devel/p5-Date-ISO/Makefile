# New ports collection makefile for:   p5-Date-ISO
# Date created:                13 May 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	Date-ISO
PORTVERSION=	1.29
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Date
PKGNAMEPREFIX=	p5-

MAINTAINER=	fuyuki@hadaly.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Date/ICal.pm:${PORTSDIR}/devel/p5-Date-ICal \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Date/Leapyear.pm:${PORTSDIR}/devel/p5-Date-Leapyear \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Memoize.pm:${PORTSDIR}/devel/p5-Memoize

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Date::ISO.3

.include <bsd.port.mk>

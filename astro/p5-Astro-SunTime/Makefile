# New ports collection makefile for:	Astro-SunTime
# Date created:				Mon Jan  1 10:06:12 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Astro-SunTime
PORTVERSION=	0.01
CATEGORIES=	astro perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Astro
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl interface to calculate sunrise/sunset times

BUILD_DEPENDS=	${SITE_PERL}/Time/ParseDate.pm:${PORTSDIR}/devel/p5-Time-modules
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

.include <bsd.port.mk>

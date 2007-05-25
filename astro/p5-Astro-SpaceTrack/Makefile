# New ports collection makefile for:	p5-Astro-SpaceTrack
# Date created:		2006-07-21
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Astro-SpaceTrack
PORTVERSION=	0.028
CATEGORIES=	astro perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Astro
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Retrieve orbital data from www.space-track.org

RUN_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN1=		SpaceTrack.1
MAN3=		Astro::SpaceTrack.3

.include <bsd.port.mk>

# New ports collection makefile for:	p5-Astro-SpaceTrack
# Date created:		2006-07-21
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Astro-SpaceTrack
PORTVERSION=	0.027
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

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600	# Inherited from www/p5-libwww
IGNORE=		requires Perl 5.6.0 or newer.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>

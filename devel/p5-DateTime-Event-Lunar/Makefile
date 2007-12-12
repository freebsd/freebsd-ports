# New ports collection makefile for:	p5-DateTime-Event-Lunar
# Date created:		2007-11-04
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Event-Lunar
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/D/DM/DMAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Compute Lunar Events

BUILD_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Set>=0:${PORTSDIR}/devel/p5-DateTime-Set \
		p5-DateTime-Util-Astro>=0.10:${PORTSDIR}/devel/p5-DateTime-Util-Astro \
		p5-Math-Round>=0:${PORTSDIR}/math/p5-Math-Round
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		DateTime::Event::Lunar.3

.include <bsd.port.mk>

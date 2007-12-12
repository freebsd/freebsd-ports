# New ports collection makefile for:	p5-DateTime-Event-SolarTerm
# Date created:		2007-11-06
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Event-SolarTerm
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/D/DM/DMAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	DateTime Extension to Calculate Solar Terms

BUILD_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Set>=0:${PORTSDIR}/devel/p5-DateTime-Set \
		p5-DateTime-Util-Calc>=0.12:${PORTSDIR}/devel/p5-DateTime-Util-Calc \
		p5-DateTime-Util-Astro>=0.11:${PORTSDIR}/devel/p5-DateTime-Util-Astro
RUN_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Set>=0:${PORTSDIR}/devel/p5-DateTime-Set \
		p5-DateTime-Util-Calc>=0.12:${PORTSDIR}/devel/p5-DateTime-Util-Calc \
		p5-DateTime-Util-Astro>=0.11:${PORTSDIR}/devel/p5-DateTime-Util-Astro

PERL_CONFIGURE=	yes

MAN3=		DateTime::Event::SolarTerm.3

.include <bsd.port.mk>

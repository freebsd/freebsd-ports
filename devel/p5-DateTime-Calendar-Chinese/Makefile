# New ports collection makefile for:	p5-DateTime-Calendar-Chinese
# Date created:		2007-11-06
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Calendar-Chinese
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/D/DM/DMAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Traditional Chinese Calendar Implementation

BUILD_DEPENDS=	p5-DateTime-Event-Chinese>=0.05:${PORTSDIR}/devel/p5-DateTime-Event-Chinese \
		p5-Math-Round>=0:${PORTSDIR}/math/p5-Math-Round \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate
RUN_DEPENDS=	p5-DateTime-Event-Chinese>=0.05:${PORTSDIR}/devel/p5-DateTime-Event-Chinese \
		p5-Math-Round>=0:${PORTSDIR}/math/p5-Math-Round \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate

PERL_CONFIGURE=	yes

MAN3=		DateTime::Calendar::Chinese.3

.include <bsd.port.mk>

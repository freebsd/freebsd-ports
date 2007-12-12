# New ports collection makefile for:	p5-DateTime-Calendar-Japanese
# Date created:		2007-11-06
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Calendar-Japanese
PORTVERSION=	0.06001
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/D/DM/DMAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	DateTime Extension for Traditional Japanese Calendars

BUILD_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Util-Calc>=0:${PORTSDIR}/devel/p5-DateTime-Util-Calc \
		p5-DateTime-Calendar-Chinese>=0:${PORTSDIR}/devel/p5-DateTime-Calendar-Chinese \
		p5-DateTime-Event-Sunrise>=0:${PORTSDIR}/devel/p5-DateTime-Event-Sunrise \
		ja-p5-DateTime-Calendar-Japanese-Era>=0:${PORTSDIR}/japanese/p5-DateTime-Calendar-Japanese-Era \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate
RUN_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Util-Calc>=0:${PORTSDIR}/devel/p5-DateTime-Util-Calc \
		p5-DateTime-Calendar-Chinese>=0:${PORTSDIR}/devel/p5-DateTime-Calendar-Chinese \
		p5-DateTime-Event-Sunrise>=0:${PORTSDIR}/devel/p5-DateTime-Event-Sunrise \
		ja-p5-DateTime-Calendar-Japanese-Era>=0:${PORTSDIR}/japanese/p5-DateTime-Calendar-Japanese-Era \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate

PERL_CONFIGURE=	yes

MAN3=		DateTime::Calendar::Japanese.3

.include <bsd.port.mk>

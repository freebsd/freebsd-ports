# New ports collection makefile for:	devel/p5-DateTime-Format-Flexible
# Date created:				23 Jun 2009
# Whom:					Cezary Morga <cm@therek.net>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Format-Flexible
PORTVERSION=	0.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cm@therek.net
COMMENT=	Flexibly parse strings and turn them into DateTime objects

RUN_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Format-Builder>=0.74:${PORTSDIR}/devel/p5-DateTime-Format-Builder \
		p5-DateTime-TimeZone>=0:${PORTSDIR}/devel/p5-DateTime-TimeZone \
		p5-Readonly>=0.06:${PORTSDIR}/devel/p5-Readonly
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	DateTime::Format::Flexible.3

.include <bsd.port.mk>

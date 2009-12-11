# New ports collection makefile for:    p5-Date-Calc-XS
# Date Created:                         11 Dec 2009
# Whom:                                 Denis Pokataev <catone@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	Date-Calc-XS
PORTVERSION=	6.2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	catone@cpan.org
COMMENT=	XS wrapper and C library plug-in for Date::Calc

BUILD_DEPENDS=	p5-Date-Calc>=6.2:${PORTSDIR}/devel/p5-Date-Calc \
		p5-Bit-Vector>=7.1:${PORTSDIR}/math/p5-Bit-Vector \
		p5-Carp-Clan>=5.3:${PORTSDIR}/devel/p5-Carp-Clan
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Date::Calc::XS.3

.include <bsd.port.mk>

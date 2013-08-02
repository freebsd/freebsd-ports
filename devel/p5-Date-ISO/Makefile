# New ports collection makefile for:   p5-Date-ISO
# Date created:                13 May 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	Date-ISO
PORTVERSION=	1.30
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts dates between ISO and Gregorian formats

BUILD_DEPENDS=	p5-Date-ICal>=1.54:${PORTSDIR}/devel/p5-Date-ICal \
		p5-Date-Leapyear>=0:${PORTSDIR}/devel/p5-Date-Leapyear
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Date::ISO.3

.include <bsd.port.mk>

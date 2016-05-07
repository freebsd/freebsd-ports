# Created by: Kimura Fuyuki <fuyuki@mj.0038.net>
# $FreeBSD$

PORTNAME=	Date-ISO
PORTVERSION=	1.31
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Converts dates between ISO and Gregorian formats

BUILD_DEPENDS=	p5-Date-ICal>=1.54:devel/p5-Date-ICal \
		p5-Date-Leapyear>=0:devel/p5-Date-Leapyear
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

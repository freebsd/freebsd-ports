# Created by: ijliao
# $FreeBSD$

PORTNAME=	Date-DayOfWeek
PORTVERSION=	1.22
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Determine the day of the week for any date

BUILD_DEPENDS=	p5-Date-Leapyear>=0:devel/p5-Date-Leapyear \
		p5-Test-Simple>=0:devel/p5-Test-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

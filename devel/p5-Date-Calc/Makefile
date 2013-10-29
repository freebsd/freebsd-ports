# Created by: Brad Hendrickse <bradh@uunet.co.za>
# $FreeBSD$

PORTNAME=	Date-Calc
PORTVERSION=	6.3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Gregorian calendar date calculations

RUN_DEPENDS=	p5-Bit-Vector>=7.1:${PORTSDIR}/math/p5-Bit-Vector \
		p5-Carp-Clan>=5.3:${PORTSDIR}/devel/p5-Carp-Clan
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

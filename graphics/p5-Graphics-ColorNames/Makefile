# Created by: Pete Fritchman <petef@databits.net>
# $FreeBSD$

PORTNAME=	Graphics-ColorNames
PORTVERSION=	2.11
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl class that defines RGB values for common color names

BUILD_DEPENDS=	p5-Module-Load>=0.10:${PORTSDIR}/devel/p5-Module-Load \
		p5-Module-Loaded>=0:${PORTSDIR}/devel/p5-Module-Loaded
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>

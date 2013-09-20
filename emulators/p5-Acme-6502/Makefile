# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Acme-6502
PORTVERSION=	0.77
CATEGORIES=	emulators perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Pure Perl 65C02 simulator

RUN_DEPENDS=	p5-Term-ReadKey>=2.30:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-version>=0.98:${PORTSDIR}/devel/p5-version
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=		Acme::6502.3 \
		Acme::6502::Tube.3

NO_STAGE=	yes
.include <bsd.port.mk>

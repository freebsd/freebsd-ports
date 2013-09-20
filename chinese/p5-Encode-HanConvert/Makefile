# Created by: Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
# $FreeBSD$

PORTNAME=	Encode-HanConvert
PORTVERSION=	0.35
CATEGORIES=	chinese perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Traditional and Simplified Chinese mappings

USES=		perl5
USE_PERL5=	configure

MAN1=		b2g.pl.1 g2b.pl.1

NO_STAGE=	yes
regression-test:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>

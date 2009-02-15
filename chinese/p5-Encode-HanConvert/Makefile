# New ports collection makefile for:	p5-Encode-HanConvert
# Date created:		15 April 2003
# Whom:	      		Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Encode-HanConvert
PORTVERSION=	0.35
CATEGORIES=	chinese perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Traditional and Simplified Chinese mappings

USE_PERL5=	5.7.3+
PERL_CONFIGURE=	yes

MAN1=		b2g.pl.1 g2b.pl.1

regression-test:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>

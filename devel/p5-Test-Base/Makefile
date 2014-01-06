# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-Base
PORTVERSION=	0.60
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Test::Base - A Data Driven Testing Framework

COMMON_DEPENDS=	p5-Spiffy>=0.30:${PORTSDIR}/devel/p5-Spiffy \
		p5-Test-Simple>=0.86:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Test-Deep>0:${PORTSDIR}/devel/p5-Test-Deep
BUILD_DEPENDS=	${COMMON_DEPENDS}
RUN_DEPENDS=	${COMMON_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

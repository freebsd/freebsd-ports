# $FreeBSD$

PORTNAME=	Chart
PORTVERSION=	2.4.6
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CHARTGRP
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to build chart graphics

BUILD_DEPENDS=	p5-GD>=2:${PORTSDIR}/graphics/p5-GD
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

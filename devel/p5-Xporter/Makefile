# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Xporter
PORTVERSION=	0.1.2
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:LAWALSH
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Alternative Exporter with persistant defaults and auto-ISA

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-mem>=0.4.5:devel/p5-mem
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502000
BUILD_DEPENDS+=	p5-ExtUtils-MakeMaker>=6.86:devel/p5-ExtUtils-MakeMaker
.endif

.include <bsd.port.post.mk>

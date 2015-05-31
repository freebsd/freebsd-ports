# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Types-Core
PORTVERSION=	0.1.4
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:LAWALSH
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Core types defined as tests and literals

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Xporter>=0.0.7:${PORTSDIR}/devel/p5-Xporter \
		p5-mem>=0.4.3:${PORTSDIR}/devel/p5-mem
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5
NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502000
BUILD_DEPENDS+=	p5-ExtUtils-MakeMaker>=6.82:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker
.endif

.include <bsd.port.post.mk>

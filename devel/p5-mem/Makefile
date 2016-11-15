# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mem
PORTVERSION=	0.4.6
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:LAWALSH
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Use "in-mem" pkgs and force definitions into mem early

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502000
BUILD_DEPENDS+=	p5-ExtUtils-MakeMaker>=6.82:devel/p5-ExtUtils-MakeMaker
.endif

.include <bsd.port.post.mk>

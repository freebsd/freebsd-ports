# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Dancer-Plugin-Redis
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CELOGEEK
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Redis database connector for Dancer

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Dancer>=0:${PORTSDIR}/www/p5-Dancer \
		p5-Redis>=1.9550:${PORTSDIR}/databases/p5-Redis
RUN_DEPENDS:=	${BUILD_DEPENDS}

PORTSCOUT=	skipv:0.10,0.11,0.12,0.13,0.14

USE_PERL5=	modbuild
USES=		perl5

.include <bsd.port.mk>

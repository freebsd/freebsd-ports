# New ports collection makefile for:	p5-Dancer-Plugin-Redis
# Date created:		31 August 2011
# Whom:			Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	Dancer-Plugin-Redis
PORTVERSION=	0.02
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CSCM
PKGNAMEPREFIX=	p5-

MAINTAINER=	magik@roorback.net
COMMENT=	Redis database connector for Dancer

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Dancer>=1.1750:${PORTSDIR}/www/p5-Dancer \
		p5-Redis>=0:${PORTSDIR}/databases/p5-Redis
RUN_DEPENDS=	p5-Dancer>=1.1750:${PORTSDIR}/www/p5-Dancer \
		p5-Redis>=0:${PORTSDIR}/databases/p5-Redis

PERL_CONFIGURE=	yes

MAN3=		Dancer::Plugin::Redis.3

.include <bsd.port.mk>

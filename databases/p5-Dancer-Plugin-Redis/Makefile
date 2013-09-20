# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Dancer-Plugin-Redis
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CSCM
PKGNAMEPREFIX=	p5-

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Redis database connector for Dancer

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Dancer>=1.1750:${PORTSDIR}/www/p5-Dancer \
		p5-Redis>=1.902:${PORTSDIR}/databases/p5-Redis
RUN_DEPENDS=	p5-Dancer>=1.1750:${PORTSDIR}/www/p5-Dancer \
		p5-Redis>=1.902:${PORTSDIR}/databases/p5-Redis

USES=		perl5
USE_PERL5=	configure

MAN3=		Dancer::Plugin::Redis.3

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -i '' -e \
		's/_check_connection($$handle->{dbh})/$$handle->{dbh}->ping/' \
		${WRKSRC}/lib/Dancer/Plugin/Redis.pm

.include <bsd.port.mk>

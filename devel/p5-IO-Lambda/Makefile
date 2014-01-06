# Created by: Vany Serezhkin <ivan@serezhkin.com>
# $FreeBSD$

PORTNAME=	IO-Lambda
PORTVERSION=	1.23
CATEGORIES=	devel perl5 parallel net www databases
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ivan@serezhkin.com
COMMENT=	Non-blocking I/O in lambda style

BUILD_DEPENDS=	p5-Sub-Name>=0.04:${PORTSDIR}/devel/p5-Sub-Name \
		p5-Net-DNS>=0.64:${PORTSDIR}/dns/p5-Net-DNS \
		p5-libwww>=5.822:${PORTSDIR}/www/p5-libwww \
		p5-URI>=1.37:${PORTSDIR}/net/p5-URI

RUN_DEPENDS:=	${BUILD_DEPENDS} \
		p5-IO-Socket-SSL>=1.19:${PORTSDIR}/security/p5-IO-Socket-SSL \
		p5-AnyEvent>=4.33:${PORTSDIR}/devel/p5-AnyEvent \
		p5-DBI>=1.60.4:${PORTSDIR}/databases/p5-DBI

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS+=	--no-online-tests

.include <bsd.port.mk>

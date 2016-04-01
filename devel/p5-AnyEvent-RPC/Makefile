# Created by: Anes Mukhametov <anes@anes.su>
# $FreeBSD$

PORTNAME=	AnyEvent-RPC
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	anes@anes.su
COMMENT=	Abstract framework for RPC clients

BUILD_DEPENDS=	p5-URI>=0:net/p5-URI \
		p5-AnyEvent>=5:devel/p5-AnyEvent \
		p5-XML-Hash-LX>=0.05:textproc/p5-XML-Hash-LX \
		p5-YAML-Syck>=0:textproc/p5-YAML-Syck \
		p5-AnyEvent-HTTP>=1.43:www/p5-AnyEvent-HTTP \
		p5-libwww>=0:www/p5-libwww \
		p5-common-sense>=2:devel/p5-common-sense \
		p5-Test-NoWarnings>=1.03:devel/p5-Test-NoWarnings \
		p5-Test-TCP>=0.14:devel/p5-Test-TCP \
		p5-lib-abs>=0.90:devel/p5-lib-abs
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

# Created by: Anes Mukhametov <anes@anes.su>
# $FreeBSD$

PORTNAME=	AnyEvent-RPC
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	anes@anes.su
COMMENT=	Abstract framework for RPC clients

BUILD_DEPENDS=	p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-AnyEvent>=5:${PORTSDIR}/devel/p5-AnyEvent \
		p5-XML-Hash-LX>=0.05:${PORTSDIR}/textproc/p5-XML-Hash-LX \
		p5-YAML-Syck>=0:${PORTSDIR}/textproc/p5-YAML-Syck \
		p5-AnyEvent-HTTP>=1.43:${PORTSDIR}/www/p5-AnyEvent-HTTP \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-common-sense>=2:${PORTSDIR}/devel/p5-common-sense \
		p5-Test-NoWarnings>=1.03:${PORTSDIR}/devel/p5-Test-NoWarnings \
		p5-Test-TCP>=0.14:${PORTSDIR}/devel/p5-Test-TCP \
		p5-lib-abs>=0.90:${PORTSDIR}/devel/p5-lib-abs
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
MAN3=		AnyEvent::RPC.3 AnyEvent::RPC::Enc::YAML.3 \
		AnyEvent::RPC::Enc::REST.3

.include <bsd.port.mk>

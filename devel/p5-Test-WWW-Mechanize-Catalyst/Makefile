# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-WWW-Mechanize-Catalyst
PORTVERSION=	0.58
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Test::WWW::Mechanize for Catalyst

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.9000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Moose>=0.67:${PORTSDIR}/devel/p5-Moose \
		p5-Test-WWW-Mechanize>=1.14:${PORTSDIR}/devel/p5-Test-WWW-Mechanize \
		p5-WWW-Mechanize>=1.54:${PORTSDIR}/www/p5-WWW-Mechanize \
		p5-libwww>=5.816:${PORTSDIR}/www/p5-libwww \
		p5-namespace-clean>=0.09:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Catalyst-Plugin-Session>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Session \
		p5-Catalyst-Plugin-Session-State-Cookie>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Session-State-Cookie \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Pod>=1.14:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-utf8>=0:${PORTSDIR}/devel/p5-Test-utf8

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>


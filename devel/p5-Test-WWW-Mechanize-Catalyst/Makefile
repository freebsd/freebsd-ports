# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-WWW-Mechanize-Catalyst
PORTVERSION=	0.60
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Test::WWW::Mechanize for Catalyst

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.9000:www/p5-Catalyst-Runtime \
		p5-Moose>=0.67:devel/p5-Moose \
		p5-Test-WWW-Mechanize>=1.14:devel/p5-Test-WWW-Mechanize \
		p5-WWW-Mechanize>=1.54:www/p5-WWW-Mechanize \
		p5-namespace-clean>=0.09:devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Catalyst-Plugin-Session>=0:www/p5-Catalyst-Plugin-Session \
		p5-Catalyst-Plugin-Session-State-Cookie>=0:www/p5-Catalyst-Plugin-Session-State-Cookie \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Pod>=1.14:devel/p5-Test-Pod \
		p5-Test-utf8>=0:devel/p5-Test-utf8

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

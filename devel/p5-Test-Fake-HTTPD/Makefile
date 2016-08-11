# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-Fake-HTTPD
PORTVERSION=	0.07
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fake HTTP server

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTTP-Daemon>=0:www/p5-HTTP-Daemon \
		p5-Plack>=0:www/p5-Plack \
		p5-Test-SharedFork>=0.29:devel/p5-Test-SharedFork \
		p5-Test-TCP>=0:devel/p5-Test-TCP \
		p5-URI>=0:net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-TCP>=0:devel/p5-Test-TCP \
		p5-Test-UseAllModules>=0:devel/p5-Test-UseAllModules \
		p5-libwww>=0:www/p5-libwww

OPTIONS_DEFINE=	SSL

USE_PERL5=	configure
USES=		perl5

SSL_BUILD_DEPENDS=	p5-HTTP-Daemon-SSL>=0:www/p5-HTTP-Daemon-SSL
SSL_RUN_DEPENDS=	p5-HTTP-Daemon-SSL>=0:www/p5-HTTP-Daemon-SSL

.include <bsd.port.mk>

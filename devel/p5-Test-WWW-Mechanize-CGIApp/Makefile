# Created by: George Hartzell <hartzell@alerce.com>
# $FreeBSD$

PORTNAME=	Test-WWW-Mechanize-CGIApp
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Test::WWW::Mechanize for CGIApp

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-CGI-Application>=0:${PORTSDIR}/www/p5-CGI-Application \
		p5-HTTP-Request-AsCGI>=0:${PORTSDIR}/www/p5-HTTP-Request-AsCGI \
		p5-Test-WWW-Mechanize>=1.14:${PORTSDIR}/devel/p5-Test-WWW-Mechanize
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

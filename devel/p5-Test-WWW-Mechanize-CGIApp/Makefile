# Created by: George Hartzell <hartzell@alerce.com>
# $FreeBSD$

PORTNAME=	Test-WWW-Mechanize-CGIApp
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Test::WWW::Mechanize for CGIApp

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-CGI-Application>=0:www/p5-CGI-Application \
		p5-HTTP-Request-AsCGI>=0:www/p5-HTTP-Request-AsCGI \
		p5-Test-WWW-Mechanize>=1.14:devel/p5-Test-WWW-Mechanize
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

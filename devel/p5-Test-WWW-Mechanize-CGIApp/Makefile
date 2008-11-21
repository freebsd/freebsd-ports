# Ports collection makefile for:	p5-Test-WWW-Mechanize-CGIApp
# Date created:				September 01, 2008
# Whom:					George Hartzell <hartzell@alerce.com>
#
# $FreeBSD$
#

PORTNAME=	Test-WWW-Mechanize-CGIApp
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hartzell@alerce.com
COMMENT=	Test::WWW::Mechanize for CGIApp

RUN_DEPENDS=	p5-CGI-Application>=0:${PORTSDIR}/www/p5-CGI-Application \
		p5-Test-WWW-Mechanize>=1.14:${PORTSDIR}/devel/p5-Test-WWW-Mechanize \
		p5-HTTP-Request-AsCGI>=0:${PORTSDIR}/www/p5-HTTP-Request-AsCGI
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=	Test::WWW::Mechanize::CGIApp.3

.include <bsd.port.mk>

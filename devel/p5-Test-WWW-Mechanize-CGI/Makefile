# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-WWW-Mechanize-CGI
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Test CGI applications with Test::WWW::Mechanize

RUN_DEPENDS=	p5-WWW-Mechanize-CGI>=0.2:www/p5-WWW-Mechanize-CGI \
		p5-Test-WWW-Mechanize>=0:devel/p5-Test-WWW-Mechanize
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

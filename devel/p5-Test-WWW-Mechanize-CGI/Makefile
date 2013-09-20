# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-WWW-Mechanize-CGI
PORTVERSION=	0.1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Test CGI applications with Test::WWW::Mechanize

RUN_DEPENDS=	p5-WWW-Mechanize-CGI>=0.2:${PORTSDIR}/www/p5-WWW-Mechanize-CGI \
		p5-Test-WWW-Mechanize>=0:${PORTSDIR}/devel/p5-Test-WWW-Mechanize
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Test::WWW::Mechanize::CGI.3

NO_STAGE=	yes
.include <bsd.port.mk>

# Created by: gerard
# $FreeBSD$

PORTNAME=	Captcha-reCAPTCHA-Mailhide
PORTVERSION=	0.94
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ANDYA
PKGNAMEPREFIX=	p5-

MAINTAINER=	gerard@seibercom.net
COMMENT=	Perl implementation of the reCAPTCHA Mailhide API

BUILD_DEPENDS=	p5-Crypt-Rijndael>=0:security/p5-Crypt-Rijndael \
		p5-HTML-Tiny>=0.904:textproc/p5-HTML-Tiny

RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

# Created by: chinsan
# $FreeBSD$

PORTNAME=	Captcha-reCAPTCHA
PORTVERSION=	0.97
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PHRED
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl implementation of the reCAPTCHA API

BUILD_DEPENDS=	p5-libwww>=0:www/p5-libwww \
		p5-HTML-Tiny>=0:textproc/p5-HTML-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

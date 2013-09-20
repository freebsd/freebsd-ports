# Created by: gerard
# $FreeBSD$

PORTNAME=	Captcha-reCAPTCHA-Mailhide
PORTVERSION=	0.94
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ANDYA
PKGNAMEPREFIX=	p5-

MAINTAINER=	gerard@seibercom.net
COMMENT=	A Perl implementation of the reCAPTCHA Mailhide API

BUILD_DEPENDS=	p5-Crypt-Rijndael>=0:${PORTSDIR}/security/p5-Crypt-Rijndael \
		p5-HTML-Tiny>=0.904:${PORTSDIR}/textproc/p5-HTML-Tiny

RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=		Captcha::reCAPTCHA::Mailhide.3

USES=		perl5
USE_PERL5=	configure

NO_STAGE=	yes
.include <bsd.port.mk>

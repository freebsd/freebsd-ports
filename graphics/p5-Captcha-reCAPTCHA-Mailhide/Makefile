# New ports collection makefile for:	p5-Captcha-reCAPTCHA-Mailhide
# Date created:				7 January 2009
# Whom:					gerard
#
# $FreeBSD$
#

PORTNAME=	Captcha-reCAPTCHA-Mailhide
PORTVERSION=	0.93
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/A/AN/ANDYA
PKGNAMEPREFIX=	p5-

MAINTAINER=	gerard@seibercom.net
COMMENT=	A Perl implementation of the reCAPTCHA Mailhide API

BUILD_DEPENDS=	p5-Crypt-Rijndael>=0:${PORTSDIR}/security/p5-Crypt-Rijndael \
		p5-HTML-Tiny>=0:${PORTSDIR}/textproc/p5-HTML-Tiny \
		p5-MIME-Base64>=0:${PORTSDIR}/converters/p5-MIME-Base64
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=		Captcha::reCAPTCHA::Mailhide.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>

# Created by: chinsan
# $FreeBSD$

PORTNAME=	Captcha-reCAPTCHA
PORTVERSION=	0.99
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SUNNYP
PKGNAMEPREFIX=	p5-
DISTNAME=	Captcha-reCaptcha-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl implementation of the reCAPTCHA API

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTML-Tiny>=0:textproc/p5-HTML-Tiny \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure
WRKSRC=		${WRKDIR}/Captcha-reCaptcha

.include <bsd.port.mk>

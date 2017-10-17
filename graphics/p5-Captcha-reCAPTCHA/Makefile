# Created by: chinsan
# $FreeBSD$

PORTNAME=	Captcha-reCAPTCHA
PORTVERSION=	0.98
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SUNNYP
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl implementation of the reCAPTCHA API

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-libwww>=0:www/p5-libwww \
		p5-HTML-Tiny>=0:textproc/p5-HTML-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure
WRKSRC=		${WRKDIR}/Captcha-reCaptcha

post-patch:
	@${FIND} ${WRKSRC} -name '._*' -delete

.include <bsd.port.mk>

# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Google-Checkout
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	devel www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Perl implementation of Google Checkout (GCO)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Crypt-SSLeay>=0.45:security/p5-Crypt-SSLeay \
		p5-Date-Manip>=5.40:devel/p5-Date-Manip \
		p5-Digest-HMAC>=1.01:security/p5-Digest-HMAC \
		p5-XML-Simple>=2.09:textproc/p5-XML-Simple \
		p5-XML-Writer>=0.6:textproc/p5-XML-Writer \
		p5-libwww>=5.65:www/p5-libwww
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

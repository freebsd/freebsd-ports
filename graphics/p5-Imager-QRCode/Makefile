# Created by: chinsan
# $FreeBSD$

PORTNAME=	Imager-QRCode
PORTVERSION=	0.03.4
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-0.034

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generate QR Code with Imager using libqrencode

BUILD_DEPENDS=	p5-Imager>=0.55:graphics/p5-Imager
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAKE_JOBS_UNSAFE=	yes

USES=		perl5
USE_PERL5=	configure
CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>

# New ports collection makefile for:	p5-Imager-QRCode
# Date created:				2007/02/28
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	Imager-QRCode
PORTVERSION=	0.03.1
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-0.031

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generate QR Code with Imager using libqrencode

BUILD_DEPENDS=	p5-Imager>=0:${PORTSDIR}/graphics/p5-Imager \
		libqrencode>=0:${PORTSDIR}/graphics/libqrencode
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include

MAN3=		Imager::QRCode.3

.include <bsd.port.mk>

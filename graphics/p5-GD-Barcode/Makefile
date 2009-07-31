# New ports collection makefile for:	p5-GD-Barcode
# Date created:				May 28 2001
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	GD-Barcode
PORTVERSION=	1.15
PORTREVISION=	2
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GD::Barcode - Create barcode image with GD

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		GD::Barcode.3 \
		GD::Barcode::COOP2of5.3 \
		GD::Barcode::Code39.3 \
		GD::Barcode::EAN13.3 \
		GD::Barcode::EAN8.3 \
		GD::Barcode::IATA2of5.3 \
		GD::Barcode::ITF.3 \
		GD::Barcode::Industrial2of5.3 \
		GD::Barcode::Matrix2of5.3 \
		GD::Barcode::NW7.3 \
		GD::Barcode::QRcode.3 \
		GD::Barcode::UPCA.3 \
		GD::Barcode::UPCE.3

.include <bsd.port.mk>

# Ports collection makefile for:  pear-Image_Barcode
# Date created:			  11 March 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Image_Barcode
PORTVERSION=	0.5
CATEGORIES=	graphics pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR class for barcode generation

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Image
FILES=		Barcode.php Barcode/int25.php Barcode/ean13.php Barcode/Code39.php
DOCS=		ChangeLog Readme.txt
TESTS=		test-image-barcode.php barcode_img.php
_DOCSDIR=	.
_TESTSDIR=	.

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>

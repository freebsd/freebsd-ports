# New ports collection makefile for:	kbarcode
# Date created:				05 July 2002
# Whom:					Andy Raffle <andy@digitalspecies.com>
#
# $FreeBSD$
#

PORTNAME=	kbarcode
PORTVERSION=	0.4.3
CATEGORIES=	graphics kde
MASTER_SITES=	ftp://ftp.kde.com/pub/Office/Organize_Track/KBarcode/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KBarcode creates, handles, manages and prints barcodes

BUILD_DEPENDS=	barcode:${PORTSDIR}/graphics/barcode

USE_KDELIBS_VER=3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL} \
		--with-extra-includes=${LOCALBASE}/include

post-install:
	${STRIP_CMD} ${PREFIX}/bin/kbarcode

.include <bsd.port.mk>

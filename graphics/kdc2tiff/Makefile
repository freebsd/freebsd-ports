# New ports collection makefile for:	kdc2tiff
# Date created:				Tue 04 Jul 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	kdc2tiff
PORTVERSION=	0.34
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts Kodak .kdc to TIFF or JPEG formats

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>

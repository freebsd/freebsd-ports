# New ports collection makefile for:	jpegpixi
# Date created:		28 May 2002
# Whom:			verm@drunkmonk.net
#
# $FreeBSD$
#

PORTNAME=	jpegpixi
PORTVERSION=	0.14
CATEGORIES=	graphics
MASTER_SITES=	http://www.zero-based.org/software/jpegpixi/
MASTER_SITE_SUBDIR=	jpegpixi

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Useful to correct images from digtal camera with CCD defects

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-jpeglib-include=${LOCALBASE}/include \
		--with-jpeglib-lib=${LOCALBASE}/lib

MAN1=		jpegpixi.1 jpeghotp.1

.include <bsd.port.mk>

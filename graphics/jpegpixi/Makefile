# New ports collection makefile for:	jpegpixi
# Date created:		28 May 2002
# Whom:			verm@drunkmonk.net
#
# $FreeBSD$
#

PORTNAME=	jpegpixi
PORTVERSION=	0.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	jpegpixi

MAINTAINER=	verm@drunkmonk.net

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-jpeglib-include=${LOCALBASE}/include \
		--with-jpeglib-lib=${LOCALBASE}/lib

.include <bsd.port.mk>

# New ports collection makefile for:	zimg
# Date created:		20 Feb 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	zimg
PORTVERSION=	4.19.1
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Image-generator that uses ASCII input files to create PNGs/EDFs

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-dynaload-cc="${CC}" \
		--with-dynaload-cflags="${CFLAGS} -shared"

MAN1=		zimg.1

.include <bsd.port.mk>

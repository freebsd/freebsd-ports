# New ports collection makefile for:	simage
# Date created:				10 May 2002
# Whom:					jesse@cs.uni-magdeburg.de
#
# $FreeBSD$
#

PORTNAME=	simage
PORTVERSION=	1.2.2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.coin3d.org/pub/coin/src/

MAINTAINER=	jesse@cs.uni-magdeburg.de

BUILD_DEPENDS=	guile:${PORTSDIR}/lang/guile
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		ungif.5:${PORTSDIR}/graphics/libungif

USE_REINPLACE=	yes
USE_XLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--program-transform-name="s/x/x/"
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|malloc.h|stdlib.h|g" ${WRKSRC}/src/resize.c

.include <bsd.port.mk>

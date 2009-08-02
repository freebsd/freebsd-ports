# New ports collection makefile for:	pixieplus
# Date created: 			3 March 2003
# Whom:					Arjan van Leeuwen <avleeuwen@piwebs.com>
#
# $FreeBSD$
#

PORTNAME=	pixieplus
PORTVERSION=	0.5.4.1
PORTREVISION=	13
CATEGORIES=	graphics kde
MASTER_SITES=	http://people.fruitsalad.org/avleeuwen/distfiles/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free, fast, and feature packed image browser and viewer for KDE

PATCH_DEPENDS=	GraphicsMagick-config:${PORTSDIR}/graphics/GraphicsMagick
LIB_DEPENDS=	GraphicsMagick.1:${PORTSDIR}/graphics/GraphicsMagick \
		ungif:${PORTSDIR}/graphics/libungif

BROKEN=		does not compile

USE_AUTOTOOLS=	libtool:22
USE_KDELIBS_VER=3
USE_LDCONFIG=	yes
USE_BZIP2=	yes
ALL_TARGET=	-j`${SYSCTL} -n hw.ncpu`

.include <bsd.port.pre.mk>

post-patch:
	# Massaging to use GraphicsMagick
	${REINPLACE_CMD} -e	\
	    "s,INCLUDES =.*,INCLUDES=`${LOCALBASE}/bin/GraphicsMagick-config \
		--cppflags` -I${LOCALBASE}/include," -e	\
	    "s|-lMagick -ltiff|`${LOCALBASE}/bin/GraphicsMagick-config \
		--libs`|" ${WRKSRC}/app/Makefile.in
	${REINPLACE_CMD} -e 's,<api.h>,<magick/api.h>,'	\
	    ${WRKSRC}/app/*.h ${WRKSRC}/app/*.cpp
	${REINPLACE_CMD} -e s,Magick-config,GraphicsMagick-config,g -e s,6.0.0,1.1.10, \
	    ${WRKSRC}/configure

.include <bsd.port.post.mk>

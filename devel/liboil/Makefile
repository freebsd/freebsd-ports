# New ports collection makefile for:	liboil
# Date created:				Nov 24, 2004
# Whom:					ijliao
#
# $FreeBSD$
#

PORTNAME=	liboil
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.schleef.org/liboil/download/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Library of optimized inner loops

USE_GNOME=	glib20
USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes

PLIST_SUB=	VERSION=${PORTVERSION:R}

post-patch:
	@${REINPLACE_CMD} -e 's|stdint\.h|inttypes.h|g' \
		${WRKSRC}/liboil/liboiltypes.h \
		${WRKSRC}/liboil/liboil.h

.include <bsd.port.mk>

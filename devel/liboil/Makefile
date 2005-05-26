# New ports collection makefile for:	liboil
# Date created:				Nov 24, 2004
# Whom:					ijliao
#
# $FreeBSD$
#

PORTNAME=	liboil
PORTVERSION=	0.3.2
CATEGORIES=	devel
MASTER_SITES=	http://www.schleef.org/liboil/download/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Library of optimized inner loops

USE_GNOME=	glib20
USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--disable-gtk-doc

PLIST_SUB=	VERSION=${PORTVERSION:R}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on FreeBSD 4.x"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|stdint\.h|inttypes.h|g' \
		${WRKSRC}/liboil/liboiltypes.h \
		${WRKSRC}/liboil/liboil.h

.include <bsd.port.post.mk>

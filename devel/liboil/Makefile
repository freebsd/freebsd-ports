# New ports collection makefile for:	liboil
# Date created:				Nov 24, 2004
# Whom:					ijliao
#
# $FreeBSD$
#

PORTNAME=	liboil
PORTVERSION=	0.3.6
CATEGORIES=	devel
MASTER_SITES=	http://liboil.freedesktop.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library of optimized inner loops

USE_GNOME=	glib20
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--disable-gtk-doc

PLIST_SUB=	VERSION=${PORTVERSION:R}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|stdint\.h|inttypes.h|g' \
		${WRKSRC}/liboil/liboiltypes.h \
		${WRKSRC}/liboil/liboilprofile.h \
		${WRKSRC}/liboil/liboil.h

.include <bsd.port.post.mk>

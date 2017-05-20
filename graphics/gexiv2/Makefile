# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gexiv2
PORTVERSION=	0.10.6
CATEGORIES=	graphics
MASTER_SITES=	GNOME/sources/gexiv2/${PORTVERSION:R}

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	GObject-based wrapper around Exiv2 library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gm4:devel/m4 \
		vala>=0:lang/vala
LIB_DEPENDS=	libexiv2.so:graphics/exiv2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-introspection=yes \
			--enable-vala=yes
USES=		gmake libtool:build pathfix pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes
MAKE_ARGS=	REQUIRED_CFLAGS="" ENABLE_INTROSPECTION=1

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/vala/vapi

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgexiv2.so
	${RM} -r ${STAGEDIR}${PREFIX}/lib/python*

.include <bsd.port.mk>

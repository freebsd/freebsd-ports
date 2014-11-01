# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gexiv2
PORTVERSION=	0.6.1
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://yorba.org/download/${PORTNAME}/${PORTVERSION:R}/
DISTNAME=	lib${PORTNAME}_${PORTVERSION}
WRKSRC=		${WRKDIR}/lib${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GObject-based wrapper around Exiv2 library

LICENSE=	GPLv2

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4
LIB_DEPENDS=	libexiv2.so:${PORTSDIR}/graphics/exiv2

USES=		gmake libtool:build pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes
MAKE_ARGS=	REQUIRED_CFLAGS="" ENABLE_INTROSPECTION=1

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|^([[:space:]]+)m4[[:space:]]|\1gm4 |' \
		-e 's|\$$\(LIB\)/pkgconfig|libdata/pkgconfig|' \
			${WRKSRC}/${MAKEFILE}

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/vala/vapi

.include <bsd.port.mk>

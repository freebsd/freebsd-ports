# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gexiv2
PORTVERSION=	0.6.1
CATEGORIES=	graphics
MASTER_SITES=	http://yorba.org/download/${PORTNAME}/${PORTVERSION:R}/
DISTNAME=	libgexiv2_${PORTVERSION}
WRKSRC=		${WRKDIR}/lib${PORTNAME}-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	GObject-based wrapper around Exiv2 library

LICENSE=	GPLv2

BUILD_DEPENDS=	libtool:${PORTSDIR}/devel/libtool \
		gm4:${PORTSDIR}/devel/m4
LIB_DEPENDS=	exiv2:${PORTSDIR}/graphics/exiv2

USES=		gmake pkgconfig
USE_XZ=		yes
USE_GNOME=	glib20
USE_LDCONFIG=	yes
MAKE_ARGS=	REQUIRED_CFLAGS=""

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|^([[:space:]]+)m4[[:space:]]|\1gm4 |' \
		-e 's|\$$\(LIB\)/pkgconfig|libdata/pkgconfig|' \
			${WRKSRC}/${MAKEFILE}

pre-install:
	@${MKDIR} ${PREFIX}/share/vala/vapi

.include <bsd.port.mk>

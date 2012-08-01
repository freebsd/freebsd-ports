# New ports collection makefile for:	gexiv2
# Date created:		Tue Sep  7 02:00:03 UTC 2010
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gexiv2
PORTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://yorba.org/download/gexiv2/${PORTVERSION:R}/
DISTNAME=	libgexiv2-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	GObject-based wrapper around the Exiv2 library

BUILD_DEPENDS=	libtool:${PORTSDIR}/devel/libtool \
		gm4:${PORTSDIR}/devel/m4
LIB_DEPENDS=	exiv2.12:${PORTSDIR}/graphics/exiv2

USE_BZIP2=	yes
USE_GNOME=	glib20
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_PKGCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|^([[:space:]]+)m4[[:space:]]|\1gm4 |' \
		-e 's|\$$\(LIB\)/pkgconfig|libdata/pkgconfig|g' \
		${WRKSRC}/${MAKEFILE}

pre-install:
	@${MKDIR} ${PREFIX}/share/vala/vapi

.include <bsd.port.mk>

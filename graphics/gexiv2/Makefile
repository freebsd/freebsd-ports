# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gexiv2
PORTVERSION=	0.6.1
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://pkgs.fedoraproject.org/repo/pkgs/libgexiv2/libgexiv2_0.6.1.tar.xz/5bd2ba92b765a2b3721874ebd2647734/
DISTNAME=	lib${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GObject-based wrapper around Exiv2 library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gm4:devel/m4
LIB_DEPENDS=	libexiv2.so:graphics/exiv2

USES=		gmake libtool:build pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes
MAKE_ARGS=	REQUIRED_CFLAGS="" ENABLE_INTROSPECTION=1
WRKSRC=		${WRKDIR}/lib${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|^([[:space:]]+)m4[[:space:]]|\1gm4 |' \
		-e 's|\$$\(LIB\)/pkgconfig|libdata/pkgconfig|' \
		-e '/^CFLAGS/ s|CFLAGS|CXXFLAGS|' \
		-e 's|\(CFLAGS\)|(CXXFLAGS)|' \
		${WRKSRC}/${MAKEFILE}

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/vala/vapi

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgexiv2.so

.include <bsd.port.mk>

# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libchamplain
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	08

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	C library provides a Gtk+ widget to display rasterized maps/markers

DEPRECATED=	Old version, not needed any more
EXPIRATION_DATE=2016-06-29

LIB_DEPENDS=	libclutter-gtk-0.10.so:graphics/clutter-gtk \
		libsoup-gnome-2.4.so:devel/libsoup-gnome

USES=		gmake libtool:keepla pathfix pkgconfig sqlite tar:bzip2
USE_GNOME=	gnomeprefix gtk20 introspection:build,run
USE_GL=		gl
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lgthread-2.0
INSTALL_TARGET=	install-strip

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
DOCSDIRGTK=	${PREFIX}/share/doc/${PORTNAME}-gtk${PKGNAMESUFFIX}

PLIST_SUB=	VERSION=0.8 DOCSDIRGTK="${DOCSDIRGTK}"

OPTIONS_DEFINE=	DOCS

post-install:
	${MV} ${STAGEDIR}${PREFIX}/share/doc/libchamplain ${STAGEDIR}${DOCSDIR}
	${MV} ${STAGEDIR}${PREFIX}/share/doc/libchamplain-gtk ${STAGEDIR}${DOCSDIRGTK}

.include <bsd.port.mk>

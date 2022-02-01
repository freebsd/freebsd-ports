# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>

PORTNAME=	gnote
PORTVERSION=	41.2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}

PATCH_SITES=	https://gitlab.gnome.org/GNOME/${PORTNAME}/-/commit/
PATCHFILES+=	32795e53681e.patch:-p1 # https://gitlab.gnome.org/GNOME/gnote/-/merge_requests/21

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ version of Tomboy, note taking application

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libenchant.so:textproc/enchant \
		libgtkspell3-3.so:textproc/gtkspell3 \
		libsecret-1.so:security/libsecret \
		libuuid.so:misc/e2fsprogs-libuuid

PORTSCOUT=	limitw:1,even

USE_GNOME=	gtkmm30 intltool libxml2 libxslt
USE_XORG=	x11
USES=		compiler:c++11-lib desktop-file-utils gettext gnome localbase \
		meson pathfix pkgconfig python:3.6+,build tar:xz xorg
USE_LDCONFIG=	yes
BINARY_ALIAS=	python3=${PYTHON_VERSION}

GLIB_SCHEMAS=	org.gnome.gnote.gschema.xml

DOCS=		AUTHORS ChangeLog NEWS README TODO

PLIST_SUB+=	SVER=${PORTVERSION:R} \
		VERSION=${PORTVERSION}

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

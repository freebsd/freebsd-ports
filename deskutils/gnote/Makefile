# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnote
PORTVERSION=	3.28.0
PORTREVISION=	2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ version of Tomboy, note taking application

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgtkspell3-3.so:textproc/gtkspell3 \
		libenchant.so:textproc/enchant \
		libsecret-1.so:security/libsecret \
		libuuid.so:misc/e2fsprogs-libuuid

PORTSCOUT=	limitw:1,even

USE_GNOME=	gtkmm30 intltool libxml2 libxslt
USE_XORG=	x11
USES=		desktop-file-utils compiler:c++11-lib gettext gmake \
		gnome libtool localbase pathfix pkgconfig tar:xz xorg
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.gnote.gschema.xml

DOCS=		AUTHORS ChangeLog NEWS README TODO

PLIST_SUB+=	VERSION=${PORTVERSION} SVER=${PORTVERSION:R}

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

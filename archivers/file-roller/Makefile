# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	file-roller
PORTVERSION=	3.16.4
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	archivers gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Archive manager for zip files, tar, etc

BUILD_DEPENDS=	itstool:textproc/itstool
RUN_DEPENDS=	gtar:archivers/gtar \
		zipinfo:archivers/unzip

# Port unzip is desired, but specify the uniquely named zipinfo to ensure
# archivers/unzip is pulled in.  Using "unzip" is satisfied by base unzip  

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gmake libarchive libtool \
		pathfix pkgconfig tar:xz
USE_GNOME=	gtk30 intlhack introspection:build
USE_XORG=	sm
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-packagekit
INSTALL_TARGET=	install-strip

PORTDOCS=	AUTHORS NEWS README TODO ChangeLog
GLIB_SCHEMAS=	org.gnome.FileRoller.gschema.xml

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	DOCS NAUTILUS
OPTIONS_DEFAULT=NAUTILUS
NAUTILUS_DESC=	Enable Nautilus extension
NAUTILUS_USE=	GNOME=nautilus3
NAUTILUS_CONFIGURE_ENABLE=	nautilus-actions

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/fr-command-tar.c \
		${WRKSRC}/src/fr-command-zip.c

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}/${DOCSDIR}
.endfor

.include <bsd.port.mk>

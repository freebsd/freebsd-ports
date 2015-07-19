# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/archivers/file-roller/Makefile 20062 2014-11-10 22:05:52Z gusi $

PORTNAME=	file-roller
PORTVERSION=	3.14.2
PORTEPOCH=	1
PORTREVISION=	1
CATEGORIES=	archivers gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Archive manager for zip files, tar, etc

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
RUN_DEPENDS=	gtar:${PORTSDIR}/archivers/gtar \
    		unzip:${PORTSDIR}/archivers/unzip

USES=		desktop-file-utils gettext gmake libtool libarchive \
		pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix gtk30 intlhack introspection:build
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
OPTIONS_DEFINE=	NAUTILUS
OPTIONS_DEFAULT=NAUTILUS
NAUTILUS_DESC=	Enable Nautilus extension
NAUTILUS_USE=	GNOME=nautilus3
NAUTILUS_CONFIGURE_ENABLE=	nautilus-actions

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/fr-command-tar.c \
		${WRKSRC}/src/fr-command-zip.c

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}/${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

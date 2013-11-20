# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/archivers/file-roller/Makefile 18897 2013-11-18 16:14:39Z kwm $

PORTNAME=	file-roller
PORTVERSION=	3.6.2
PORTEPOCH=	1
CATEGORIES=	archivers gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An archive manager for zip files, tar, etc

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
RUN_DEPENDS=	${LOCALBASE}/bin/gtar:${PORTSDIR}/archivers/gtar \
    		${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip

USE_LDCONFIG=	yes
USE_XZ=		yes
USES=		desktop-file-utils gettext gmake pathfix pkgconfig
INSTALLS_ICONS=	yes
USE_GNOME=	gconf2 gnomeprefix gtk30 intlhack \
		introspection:build
USE_XORG=	sm
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-packagekit

PORTDOCS=	AUTHORS NEWS README TODO ChangeLog
GLIB_SCHEMAS=	org.gnome.FileRoller.gschema.xml

OPTIONS_DEFINE=	NAUTILUS
OPTIONS_DEFAULT=NAUTILUS
NAUTILUS_DESC=	Enable Nautilus extension

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNAUTILUS}
USE_GNOME+=	nautilus3
PLIST_SUB+=	NAUTILUS=""
.else
PLIST_SUB+=	NAUTILUS="@comment "
CONFIGURE_ARGS+=--disable-nautilus-actions
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/fr-command-tar.c \
		${WRKSRC}/src/fr-command-zip.c

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}/${DOCSDIR}
.endfor
.endif
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/nautilus/extensions-3.0/libnautilus-fileroller.so


.include <bsd.port.mk>


# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/archivers/file-roller/Makefile,v 1.184 2010/11/15 22:58:48 kwm Exp $

PORTNAME=	file-roller
PORTVERSION=	2.32.1
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	archivers gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Archive manager for zip files, tar, etc

RUN_DEPENDS=	${LOCALBASE}/bin/gtar:${PORTSDIR}/archivers/gtar \
    		${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip

USES=		desktop-file-utils gettext gmake libtool \
		pathfix pkgconfig tar:bzip2
USE_GNOME=	gnomeprefix intlhack gnomedocutils gtk20 gconf2
USE_XORG=	sm
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
GNOME_DESKTOP_VERSION=2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-packagekit
INSTALL_TARGET=	install-strip

PORTDOCS=	AUTHORS NEWS README TODO ChangeLog
GCONF_SCHEMAS=	file-roller.schemas

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	DOCS NAUTILUS
NAUTILUS_DESC=	Enable Nautilus extension

OPTIONS_DEFAULT=NAUTILUS

NAUTILUS_USE=	GNOME=nautilus2
NAUTILUS_CONFIGURE_OFF=	--disable-nautilus-actions

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/fr-command-tar.c \
		${WRKSRC}/src/fr-command-zip.c

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

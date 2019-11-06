# Created by: Andreev Maxim
# $FreeBSD$

PORTNAME=	xarchiver
PORTVERSION=	0.5.4.7
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	archivers

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Desktop-agnostic GTK+2 frontend to various archiving tools

BROKEN=		unfetchable

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	xdg-open:devel/xdg-utils \
		7zr:archivers/p7zip \
		zip:archivers/zip \
		zipinfo:archivers/unzip

USE_GITHUB=	yes
GH_ACCOUNT=	ib

USES=		desktop-file-utils gmake gnome pkgconfig
USE_GNOME=	cairo glib20 intltool
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_GROUP=	FORMATS
OPTIONS_GROUP_FORMATS=	ARJ LZO RAR
OPTIONS_SINGLE=		GTK
OPTIONS_SINGLE_GTK=	GTK2 GTK3
OPTIONS_DEFAULT=	GTK2
OPTIONS_SUB=	yes

FORMATS_DESC=	Additional compression formats support
ARJ_DESC=	ARJ compression support
LZO_DESC=	LZO compression support
RAR_DESC=	RAR compression support

ARJ_RUN_DEPENDS=	arj:archivers/arj
LZO_RUN_DEPENDS=	lzop:archivers/lzop
RAR_RUN_DEPENDS=	unrar:archivers/unrar \
			rar:archivers/rar

GTK2_CONFIGURE_ENABLE=	gtk2
GTK2_USE=		GNOME=gtk20
GTK3_USE=		GNOME=gtk30

NLS_USES=	gettext localbase
NLS_USES_OFF=	gettext-tools

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e 's|doc||g' ${WRKSRC}/Makefile.in

post-patch-NLS-off:
	@${REINPLACE_CMD} -e 's| po | |g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>

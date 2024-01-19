PORTNAME=	xarchiver
DISTVERSION=	0.5.4.22
CATEGORIES=	archivers

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	5c49e86ffe16cc8a98018ff2f4d2e0ea2b9c0b6c.patch:-p1 # (bsd)sed fix: https://github.com/ib/xarchiver/issues/186

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Desktop-agnostic GTK frontend to various archiving tools
WWW=		https://github.com/ib/xarchiver

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	${LOCALBASE}/bin/gzip:archivers/gzip \
		${LOCALBASE}/bin/unzip:archivers/unzip \
		7zz:archivers/7-zip \
		gtar:archivers/gtar \
		xdg-open:devel/xdg-utils \
		zip:archivers/zip

USES=		desktop-file-utils gmake gnome libtool:build pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	ib
USE_GNOME=	cairo gdkpixbuf2 glib20 intltool

GNU_CONFIGURE=	yes

PORTSCOUT=	limit:^\d\.\d\.\d\.\d+$ # avoid tags like identical_to_xfce_git_content

OPTIONS_DEFINE=		DOCS NLS
OPTIONS_DEFAULT=	GTK3
OPTIONS_GROUP=		FORMATS
OPTIONS_GROUP_FORMATS=	ARJ LZO RAR
OPTIONS_SINGLE=		GTK
OPTIONS_SINGLE_GTK=	GTK2 GTK3
OPTIONS_SUB=		yes

ARJ_DESC=	ARJ compression support
FORMATS_DESC=	Additional compression formats support
RAR_DESC=	RAR compression support

ARJ_RUN_DEPENDS=	arj:archivers/arj
LZO_RUN_DEPENDS=	lzop:archivers/lzop
RAR_RUN_DEPENDS=	rar:archivers/rar \
			unrar:archivers/unrar

DOCS_BUILD_DEPENDS=	xsltproc:textproc/libxslt
DOCS_CONFIGURE_ENABLE=	doc

GTK2_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2
GTK2_USE=		GNOME=gtk20
GTK2_CONFIGURE_ENABLE=	gtk2

GTK3_USE=	GNOME=gtk30

NLS_USES=		gettext localbase
NLS_USES_OFF=		gettext-tools
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/main.c

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS /s| po||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>

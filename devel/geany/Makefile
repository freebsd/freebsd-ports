# Created by: Remington Lang <MrL0Lz@gmail.com>
# $FreeBSD$

PORTNAME=	geany
PORTVERSION=	1.36
CATEGORIES=	devel editors
MASTER_SITES=	http://download.geany.org/ SF

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Fast and lightweight GTK+ IDE

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

FLAVORS=	gtk3 gtk2
FLAVOR?=	${FLAVORS:[1]}

gtk2_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2
gtk2_CONFLICTS_INSTALL=	geany
gtk2_PKGNAMESUFFIX=	-gtk2

gtk3_CONFLICTS_INSTALL=	geany-gtk2

USES=		compiler:c++11-lang desktop-file-utils gettext-tools gmake \
		gnome libtool localbase pathfix pkgconfig python:build \
		shebangfix tar:bzip2
USE_GNOME=	cairo intltool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
SHEBANG_FILES=	scripts/gen-api-gtkdoc.py

OPTIONS_DEFINE=	DOCS NLS THEMES VTE
OPTIONS_DEFAULT=	VTE
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

VTE_DESC=	Embedded virtual terminal
VTE_CONFIGURE_ENABLE=	vte
VTE_USE=	GNOME=vte

THEMES_DESC=	Additional color schemes
THEMES_RUN_DEPENDS=	${LOCALBASE}/share/geany/colorschemes/bespin.conf:devel/geany-themes

.if ${FLAVOR} == gtk2
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=	--disable-gtk3
PLIST_SUB+=	GTK2="" GTK3="@comment "
.elif ${FLAVOR} == gtk3
USE_GNOME+=	gtk30
CONFIGURE_ARGS+=	--enable-gtk3
PLIST_SUB+=	GTK2="@comment " GTK3=""
.endif

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS/ s|doc||' ${WRKSRC}/Makefile.in

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS/ s|po||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>

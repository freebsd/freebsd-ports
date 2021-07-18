# Created by: Michael Reifenberger <mr@FreeBSD.org>

PORTNAME=	pcb
PORTVERSION=	4.2.0
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	X11 interactive printed circuit board layout system

LICENSE=	GPLv2

BUILD_DEPENDS=	m4>=1.4.11:devel/m4 \
		${LOCALBASE}/libdata/pkgconfig/dbus-1.pc:devel/dbus
LIB_DEPENDS=	libgd.so:graphics/gd \
		libgtkglext-x11-1.0.so:x11-toolkits/gtkglext \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	m4>=1.4.11:devel/m4 \
		${LOCALBASE}/libdata/pkgconfig/dbus-1.pc:devel/dbus

USES=		gl gmake gnome pkgconfig tk:run shared-mime-info \
		desktop-file-utils xorg
USE_GL=		gl glu
USE_GNOME=	intltool cairo pangox-compat
USE_XORG=	x11 xrender xinerama

CONFLICTS=	gts-[0-9]*
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	INSTALL_DATA="${BSD_INSTALL_DATA}"
LDFLAGS+=	-lpthread

PORTDOCS=	\
	pcb.html pcb.pdf refcard.pdf pad.png puller.png thermal.png	\
	examples tutorial gcode.png gcode_control_img.png		\
	gcode_tool_path.png

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SINGLE=	GUI
OPTIONS_SINGLE_GUI=MOTIF GTK NONE
OPTIONS_DEFAULT=GTK
DOCS_CONFIGURE_ENABLE=	doc
DOCS_CONFIGURE_ON=	--docdir=${DOCSDIR}
NLS_CONFIGURE_ENABLE=	nls
NLS_CONFIGURE_ON=	--with-libintl-prefix=${LOCALBASE} \
			${ICONV_CONFIGURE_ARG}
NLS_CONFIGURE_OFF=	--without-libintl \
			--without-iconv
NLS_USES=	gettext iconv
.for L in fr nl ru pt_BR
NLS_PLIST_FILES+=	share/locale/${L}/LC_MESSAGES/pcb.mo
.endfor
MOTIF_DESC=	Motif widgets
MOTIF_USES=	motif
MOTIF_CONFIGURE_ON=	--with-gui=lesstif
MOTIF_CONFIGURE_ENV=	WISH=${WISH}
GTK_DESC=	GIMP ToolKit widgets
GTK_USE=	GNOME=gtk20
GTK_CONFIGURE_ON=	--with-gui=gtk
GTK_CONFIGURE_ENV=	WISH=${WISH}
NONE_DESC=	No GUI support
NONE_CONFIGURE_ON=	--without-gui
NONE_CONFIGURE_ENV=	WISH=/usr/bin/true

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	Uses x86 specific libc functions and has not been ported

DOCS_INFO=		pcb

.include <bsd.port.mk>

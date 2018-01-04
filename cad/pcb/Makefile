# Created by: Michael Reifenberger <mr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pcb
PORTVERSION=	20140316
PORTREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	X11 interactive printed circuit board layout system

LICENSE=	GPLv2

LIB_DEPENDS=	libgd.so:graphics/gd \
		libgtkglext-x11-1.0.so:x11-toolkits/gtkglext
RUN_DEPENDS=	m4>=1.4.11:devel/m4 \
		${LOCALBASE}/libdata/pkgconfig/dbus-1.pc:devel/dbus
BUILD_DEPENDS:=	${RUN_DEPENDS}

CONFLICTS=	gts-[0-9]*

USES=		gmake pkgconfig tk:run shared-mime-info desktop-file-utils
USE_GNOME=	intltool
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	INSTALL_DATA="${BSD_INSTALL_DATA}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib

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

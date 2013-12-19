# Created by: Michael Reifenberger <mr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pcb
PORTVERSION=	20110918
PORTREVISION=	3
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	X11 interactive printed circuit board layout system

LICENSE=	GPLv2

LIB_DEPENDS=	libgd.so:${PORTSDIR}/graphics/gd \
		libgtkglext-x11-1.0.so:${PORTSDIR}/x11-toolkits/gtkglext
RUN_DEPENDS=	m4>=1.4.11:${PORTSDIR}/devel/m4 \
		${LOCALBASE}/libdata/pkgconfig/dbus-1.pc:${PORTSDIR}/devel/dbus
BUILD_DEPENDS:=	${RUN_DEPENDS}

USE_AUTOTOOLS=	autoconf
USES=		gmake pkgconfig
USE_TK_RUN=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	INSTALL_DATA="${BSD_INSTALL_DATA}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-pthread -L${LOCALBASE}/lib
CONFIGURE_ARGS= --docdir=${DOCSDIR}

PORTDOCS= pcb.html pcb.pdf refcard.pdf pad.png puller.png thermal.png	\
	examples tutorial gcode.png gcode_control_img.png		\
	gcode_tool_path.png

OPTIONS_DEFINE=	DOCS NLS X11
OPTIONS_SINGLE=	GUI
OPTIONS_SINGLE_GUI=MOTIF GTK NONE
OPTIONS_DEFAULT=DOCS X11 GTK
MOTIF_DESC=	Motif widgets
GTK_DESC=	GIMP ToolKit widgets
NONE_DESC=	No GUI support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+= \
	--enable-nls \
	${ICONV_CONFIGURE_ARG} \
	--with-libintl-prefix=${LOCALBASE}
USES+=		gettext iconv
.for L in fr nl ru
PLIST_FILES+=	share/locale/${L}/LC_MESSAGES/pcb.mo
.endfor
.else
CONFIGURE_ARGS+= \
	--disable-nls \
	--without-libiconv \
	--without-libintl
.endif

.if ${PORT_OPTIONS:MX11}
.if ${PORT_OPTIONS:MNONE}
CONFIGURE_ARGS+=	--without-gui
CONFIGURE_ENV+=		WISH=${TRUE}
.elif ${PORT_OPTIONS:MMOTIF}
USES+=		motif
USE_TK_RUN=	yes
CONFIGURE_ARGS+=	--with-gui=lesstif
CONFIGURE_ENV+=		WISH=${WISH}
.elif ${PORT_OPTIONS:MGTK}
USE_GNOME=	gtk20 desktopfileutils
USE_TK_RUN=	yes
CONFIGURE_ARGS+=	--with-gui=gtk
CONFIGURE_ENV+=		WISH=${WISH}
.endif
.endif

.if ${PORT_OPTIONS:MDOCS}
INFO=		pcb
MAN1=		pcb.1
.else
CONFIGURE_ARGS+=	--disable-doc
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	oxim
# Date created:				Mar 19 2006
# Whom:					Rong-En Fan <rafan@infor.org>
#
# $FreeBSD$
#

PORTNAME=	oxim
PORTVERSION=	1.0.3
CATEGORIES=	chinese textproc
MASTER_SITES=	ftp://apt.nc.hcc.edu.tw/pub/mirror/opendesktop.org.tw/OXIM/Source/ \
		ftp://ftp4.tnc.edu.tw/pub3/opendesktop-tw/odp/ \
		ftp://140.111.128.66/odp/OXIM/Source/

MAINTAINER=	rafan@infor.org
COMMENT=	Open X Input Method server

# make sure we have the required libchewing
LIB_DEPENDS=	Xft.2:${PORTSDIR}/x11-fonts/libXft
BUILD_DEPENDS=	zh-libchewing>=0.2.6:${PORTSDIR}/chinese/libchewing
RUN_DEPENDS=	zh-libchewing>=0.2.6:${PORTSDIR}/chinese/libchewing \
		zh-fireflyttf>=0:${PORTSDIR}/chinese/fireflyttf

BROKEN=		Does not compile

OPTIONS=	GTK2 "Enable GTK2 input method module" On

USE_GCC=	3.2+
USE_ICONV=	yes
USE_X_PREFIX=	yes
USE_GNOME=

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -liconv
CONFIGURE_ENV+=	CONFIG_SHELL=${SH} \
		CHEWING_CFLAGS=-I${LOCALBASE}/include \
		CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=--disable-bimsphone-module \
		--disable-static \
		--with-conf-dir=${PREFIX}/etc/${PORTNAME}

.include <bsd.port.pre.mk>

.if defined(WITHOUT_GTK2)
CONFIGURE_ARGS+=	--disable-gtk-immodule
PLIST_SUB+=	GTK2="@comment "
.else
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=	--enable-gtk-immodule
PLIST_SUB+=	GTK2=""
.endif

# TODO WITHOUT_NLS knob
#.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
LDFLAGS+=	-lintl
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
#.else
#CONFIGURE_ARGS+=--disable-nls
#PLIST_SUB+=	NLS="@comment "
#.endif

post-patch:
	${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|' \
			${WRKSRC}/src/gtk-immodule/gtkintl.h

post-install:
.if !defined(WITHOUT_GTK2)
	@gtk-query-immodules-2.0 > ${PREFIX}/etc/gtk-2.0/gtk.immodules
.endif
	@${CAT} ${PKGMESSAGE}
	@${ECHO} To display this message again, type ${PKG_INFO} -D ${PKGNAME}

.include <bsd.port.post.mk>

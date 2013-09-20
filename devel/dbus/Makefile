# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/dbus/Makefile,v 1.58 2013/02/15 15:06:49 kwm Exp $

PORTNAME=	dbus
PORTVERSION=	1.6.12
CATEGORIES=	devel gnome
MASTER_SITES=	http://dbus.freedesktop.org/releases/dbus/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A message bus system for inter-application communication

LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2

PORTSCOUT=	limitw:1,even

USE_GNOME=	gnomehack libxml2 ltverhack
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CONFIGURE_ARGS=--localstatedir=/var \
	        --with-test-socket-dir=${WRKDIR} \
		--with-system-pid-file=/var/run/dbus/dbus.pid \
		--with-system-socket=/var/run/dbus/system_bus_socket \
		--with-session-socket-dir=/tmp \
		--disable-doxygen-docs \
		--disable-xml-docs
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_RC_SUBR=	dbus
USE_GNOME_SUBR=	yes

USERS=		messagebus
GROUPS=		messagebus

PLIST_SUB=	VERSION="1.0"

MAN1=		dbus-cleanup-sockets.1 dbus-daemon.1 dbus-launch.1 \
		dbus-monitor.1 dbus-send.1 dbus-uuidgen.1

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11
X11_DESC=	Support X11 Desktop Environments

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USE_XORG=	ice sm x11
.else
CONFIGURE_ARGS+=--without-x
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/dbus/dbus-sysdeps-unix.c
	@${REINPLACE_CMD} -e 's|/lib/dbus/machine-id|/db/dbus/machine-id|g' \
		${WRKSRC}/doc/dbus-uuidgen.1 \
		${WRKSRC}/dbus/Makefile.in \
		${WRKSRC}/tools/Makefile.in
	@${REINPLACE_CMD} '/^SUBDIRS/,/^$$/ s|test||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|THREAD_LIBS -lrt|THREAD_LIBS|g ; \
		s|dummy man2html|dummy man2html_disable|g' \
			${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|install-data-am: install-data-local|install-data-am:|g' \
		${WRKSRC}/tools/Makefile.in

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	${MKDIR} ${PREFIX}/share/dbus-1/interfaces

.include <bsd.port.mk>

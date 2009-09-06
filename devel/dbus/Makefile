# New ports collection makefile for:   D-BUS
# Date Created:			22 June 2004
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dbus
PORTVERSION?=	1.2.4.6
PORTREVISION?=	1
CATEGORIES=	devel gnome
MASTER_SITES=	http://dbus.freedesktop.org/releases/dbus/
DISTNAME=	dbus-${PORTVERSION}permissive

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A message bus system for inter-application communication

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

USE_GNOME?=	gnomehack libxml2 ltverhack
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
CONFIGURE_ARGS=--localstatedir=/var \
	        --with-test-socket-dir=${WRKDIR} \
		--with-system-pid-file=/var/run/dbus/dbus.pid \
		--with-system-socket=/var/run/dbus/system_bus_socket \
		--with-session-socket-dir=/var/tmp \
		--disable-doxygen-docs \
		--disable-xml-docs
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

.if !defined(DBUS_SLAVE)
USE_RC_SUBR=	dbus
USE_GNOME_SUBR=	yes

USERS=		messagebus
GROUPS=		messagebus

PLIST_SUB=	VERSION="1.0"

MAN1=		dbus-cleanup-sockets.1 dbus-daemon.1 dbus-launch.1 \
		dbus-monitor.1 dbus-send.1 dbus-uuidgen.1

.if !defined(WITHOUT_X11)
USE_XORG=	x11
.else
CONFIGURE_ARGS+=--without-x
.endif
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/dbus/dbus-sysdeps-unix.c
	@${REINPLACE_CMD} -e 's|/lib/dbus/machine-id|/db/dbus/machine-id|g' \
		${WRKSRC}/dbus/Makefile.in \
		${WRKSRC}/tools/Makefile.in

.if !defined(DBUS_SLAVE)
post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	${MKDIR} ${PREFIX}/share/dbus-1/interfaces
.endif

.include <bsd.port.post.mk>

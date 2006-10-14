# New ports collection makefile for:   D-BUS
# Date Created:			22 June 2004
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dbus
PORTVERSION?=	0.93
PORTREVISION?=	2
CATEGORIES=	devel gnome
MASTER_SITES=	http://dbus.freedesktop.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A message bus system for inter-application communication

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

USE_GNOME=	gnomehack gnometarget libxml2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=--localstatedir=/var \
	        --with-test-socket-dir=${WRKDIR} \
		--with-system-pid-file=/var/run/dbus/dbus.pid \
		--with-system-socket=/var/run/dbus/dbus.pipe \
		--with-session-socket-dir=/var/tmp \
		--disable-doxygen-docs \
		--disable-xml-docs
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

.if !defined(DBUS_SLAVE)
USE_RC_SUBR=	dbus

PLIST_SUB=	VERSION="1.0"

MAN1=		dbus-cleanup-sockets.1 dbus-daemon.1 dbus-launch.1 \
		dbus-monitor.1 dbus-send.1

.if !defined(WITHOUT_X11)
USE_XLIB=	yes
.endif
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|' \
		${WRKSRC}/bus/session.conf.in \
		${WRKSRC}/bus/system.conf.in

.if !defined(DBUS_SLAVE)
post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	${MKDIR} ${X11BASE}/etc/dbus-1/system.d
	${MKDIR} ${X11BASE}/share/dbus-1/services

.endif

.include <bsd.port.post.mk>

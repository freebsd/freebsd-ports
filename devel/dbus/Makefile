# New ports collection makefile for:   D-BUS
# Date Created:			22 June 2004
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/dbus/Makefile,v 1.51 2011/08/30 08:13:48 kwm Exp $
#

PORTNAME=	dbus
PORTVERSION=	1.4.14
PORTREVISION=	3
CATEGORIES=	devel gnome
MASTER_SITES=	http://dbus.freedesktop.org/releases/dbus/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A message bus system for inter-application communication

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

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
CONFIGURE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

USE_RC_SUBR=	dbus
USE_GNOME_SUBR=	yes

USERS=		messagebus
GROUPS=		messagebus

PLIST_SUB=	VERSION="1.0"

MAN1=		dbus-cleanup-sockets.1 dbus-daemon.1 dbus-launch.1 \
		dbus-monitor.1 dbus-send.1 dbus-uuidgen.1

.if !defined(WITHOUT_X11)
USE_XORG=	ice sm x11
.else
CONFIGURE_ARGS+=--without-x
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/dbus/dbus-sysdeps-unix.c
	@${REINPLACE_CMD} -e 's|/lib/dbus/machine-id|/db/dbus/machine-id|g' \
		${WRKSRC}/dbus/Makefile.in \
		${WRKSRC}/tools/Makefile.in
	@${REINPLACE_CMD} '/^SUBDIRS/,/^$$/ s|test||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|THREAD_LIBS -lrt|THREAD_LIBS|g ; \
		s|dummy man2html|dummy man2html_disable|g' \
			${WRKSRC}/configure

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	${MKDIR} ${PREFIX}/share/dbus-1/interfaces

.include <bsd.port.mk>

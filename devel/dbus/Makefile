# New ports collection makefile for:   D-BUS
# Date Created:			22 June 2004
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dbus
PORTVERSION=	0.61
PORTREVISION?=	3
CATEGORIES?=	devel gnome
MASTER_SITES=	http://dbus.freedesktop.org/releases/

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	A message bus system for inter-application communication

LIB_DEPENDS?=	expat.6:${PORTSDIR}/textproc/expat2

USE_GNOME?=	gnomehack glib20 libxml2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS?=--disable-gtk \
		--disable-python \
		--disable-gcj \
		--disable-qt \
		--disable-mono \
		--disable-mono-docs \
		--localstatedir=/var \
		--with-system-pid-file=/var/run/dbus/dbus.pid \
		--with-system-socket=/var/run/dbus/dbus.pipe \
		--with-session-socket-dir=/var/tmp \
		--disable-doxygen-docs \
		--disable-xml-docs
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if !defined(DBUS_SLAVE)
USE_RC_SUBR=	dbus
OPTIONS=	QT "Enable Qt client support" off

PLIST_SUB=	VERSION="1.0"

MAN1=		dbus-cleanup-sockets.1 dbus-daemon.1 dbus-launch.1 \
		dbus-monitor.1 dbus-send.1
.endif

.include <bsd.port.pre.mk>

.if !defined(DBUS_SLAVE)
.if defined(WITH_QT) && !defined(WITHOUT_QT)
CONFIGURE_ARGS+=--enable-qt3
CONFIGURE_ENV+=	QTDIR=${X11BASE}
LIB_DEPENDS+=	qt-mt:${PORTSDIR}/x11-toolkits/qt33
PLIST_SUB+=	QT=""
.else
PLIST_SUB+=	QT="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|' \
		${WRKSRC}/bus/session.conf.in \
		${WRKSRC}/bus/system.conf.in

.if !defined(DBUS_SLAVE)
pre-su-install:
	@for i in 15 9 ; do \
		if [ -f /var/run/dbus/dbus.pid ]; then \
			kill -$${i} $$(${CAT} /var/run/dbus/dbus.pid) 2>/dev/null || ${TRUE} ; \
			sleep 3 ; \
		fi ; \
	done
	@if [ -f /var/run/dbus/dbus.pid ]; then \
		${RM} -f /var/run/dbus/dbus.pid ; \
	fi
.endif

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	${MKDIR} ${X11BASE}/etc/dbus-1/system.d
	${MKDIR} ${X11BASE}/share/dbus-1/services
.else
.if defined(PKGNAMEPREFIX)
.if ${PKGNAMEPREFIX}==${PYTHON_PKGNAMEPREFIX} && ${OSVERSION} < 500000
# Ignore for py-dbus
IGNORE=	does not build on 4.X
.endif
.endif

.endif

.include <bsd.port.post.mk>

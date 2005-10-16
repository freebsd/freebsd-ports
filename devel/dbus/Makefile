# New ports collection makefile for:   D-BUS
# Date Created:			22 June 2004
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dbus
PORTVERSION=	0.36.2
PORTREVISION?=	0
CATEGORIES?=	devel gnome
MASTER_SITES=	http://dbus.freedesktop.org/releases/

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	A message bus system for inter-application communication

BUILD_DEPENDS?=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS?=	expat.5:${PORTSDIR}/textproc/expat2

USE_GNOME?=	gnomehack glib20 libxml2
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
USE_RC_SUBR=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS?=--disable-gtk \
		--disable-python \
		--disable-gcj \
		--disable-mono \
		--disable-mono-docs \
		--with-system-pid-file=/var/run/dbus.pid \
		--with-system-socket=/var/run/dbus \
		--with-session-socket-dir=/var/tmp \
		--disable-doxygen-docs \
		--disable-xml-docs
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if !defined(DBUS_SLAVE)
OPTIONS=	QT "Enable Qt client support" off

PLIST_SUB=	VERSION="1.0"
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

MAN1=		dbus-cleanup-sockets.1 dbus-daemon.1 dbus-launch.1 \
		dbus-monitor.1 dbus-send.1
.endif

.include <bsd.port.pre.mk>

.if !defined(DBUS_SLAVE)
.if defined(WITH_QT) && !defined(WITHOUT_QT)
CONFIGURE_ARGS+=--enable-qt
CONFIGURE_ENV+=	QTDIR=${X11BASE}
LIB_DEPENDS+=	qt-mt:${PORTSDIR}/x11-toolkits/qt33
PLIST_SUB+=	QT=""
.else
CONFIGURE_ARGS+=--disable-qt
PLIST_SUB+=	QT="@comment "
.endif

post-patch:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/dbus.sh > ${WRKSRC}/dbus.sh
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/tools/run-with-tmp-session-bus.sh
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|' \
		${WRKSRC}/bus/session.conf.in

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/dbus.sh ${PREFIX}/etc/rc.d
	${MKDIR} ${X11BASE}/share/dbus-1/services
.else
.if defined(PKGNAMEPREFIX)
.if ${PKGNAMEPREFIX}==${PYTHON_PKGNAMEPREFIX} && ${OSVERSION} < 500000
IGNORE=	Does not build on 4.X
.endif
.endif

.endif

.include <bsd.port.post.mk>

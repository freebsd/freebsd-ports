# New ports collection makefile for:   D-BUS
# Date Created:			22 June 2004
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dbus
PORTVERSION=	0.21
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	http://freedesktop.org/Software/dbus/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A message bus system for inter-application communication

LIB_DEPENDS=	expat.5:${PORTSDIR}/textproc/expat2

USE_GNOME=	gnomehack gtk20 libxml2
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
USE_RC_SUBR=	yes
USE_PYTHON=	yes
CONFIGURE_ARGS=	--enable-gtk \
		--disable-python \
		--disable-gcj \
		--disable-mono \
		--with-system-pid-file=/var/run/dbus.pid \
		--with-system-socket=/var/run/dbus \
		--with-session-socket-dir=/var/tmp \
		--disable-doxygen-docs \
		--disable-xml-docs
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	QT "Enable Qt client support" off

PLIST_SUB=	VERSION="1.0"
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

MAN1=		dbus-cleanup-sockets.1 dbus-daemon-1.1 dbus-launch.1 \
		dbus-monitor.1 dbus-send.1

.include <bsd.port.pre.mk>

.if defined(WITH_QT) && !defined(WITHOUT_QT)
CONFIGURE_ARGS+=--enable-qt
PLIST_SUB+=	QT=""
.else
CONFIGURE_ARGS+=--disable-qt
PLIST_SUB+=	QT="@comment "
.endif

post-patch:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/dbus.sh > ${WRKSRC}/dbus.sh

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/dbus.sh ${PREFIX}/etc/rc.d

.include <bsd.port.post.mk>

# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	dbus-glib
PORTVERSION=	0.86
PORTREVISION=	1
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	GLib bindings for D-Bus (Linux CentOS ${LINUX_DIST_VER})

USE_LINUX=	c6
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	dbuslibs expat

RPMVERSION=	6.el6
BRANDELF_FILES=	usr/bin/dbus-binding-tool
USE_LDCONFIG=	yes

PLIST_FILES=	usr/bin/dbus-binding-tool usr/lib/libdbus-glib-1.so.2 \
		usr/lib/libdbus-glib-1.so.2.1.0
DOCSDIR=	usr/share/doc/dbus-glib-0.86
PORTDOCS=	COPYING ChangeLog NEWS
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>

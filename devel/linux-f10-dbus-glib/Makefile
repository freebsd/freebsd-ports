# Created by: bsam
# $FreeBSD$

PORTNAME=	dbus-glib
PORTVERSION=	0.76
PORTREVISION=	1
CATEGORIES=	devel linux
MASTER_SITES=	LOCAL/ehaupt/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	GLib bindings for D-Bus (Linux Fedora 10)

USE_LINUX=	f10
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	dbuslibs expat

RPMVERSION=	3.fc10
BRANDELF_FILES=	usr/bin/dbus-binding-tool
USE_LDCONFIG=	yes

PLIST_FILES=	usr/bin/dbus-binding-tool usr/lib/libdbus-glib-1.so.2 \
		usr/lib/libdbus-glib-1.so.2.1.0
DOCSDIR=	usr/share/doc/dbus-glib-0.76
PORTDOCS=	COPYING ChangeLog NEWS
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>

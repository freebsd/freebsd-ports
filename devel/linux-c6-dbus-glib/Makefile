# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	dbus-glib
PORTVERSION=	0.86
PORTREVISION=	2
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	GLib bindings for D-Bus (Linux CentOS ${LINUX_DIST_VER})

USE_LINUX=	c6
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	dbuslibs expat

RPMVERSION=	6.el6
BRANDELF_FILES=	usr/bin/dbus-binding-tool
USE_LDCONFIG=	yes

DOCSDIR=	usr/share/doc/dbus-glib-0.86
PORTDOCS=	COPYING ChangeLog NEWS
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>

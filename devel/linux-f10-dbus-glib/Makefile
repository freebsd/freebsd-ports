# New ports collection makefile for:	devel/linux-f10-dbus-glib
# Date created:				2009-07-27
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	dbus-glib
PORTVERSION=	0.76
CATEGORIES=	devel linux
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	GLib bindings for D-Bus (Linux Fedora 10)

USE_LINUX_RPM=	yes
USE_LINUX_APPS=	dbuslibs expat
LINUX_DIST_VER=	10
RPMVERSION=	3.fc10
BRANDELF_FILES=	usr/bin/dbus-binding-tool
USE_LDCONFIG=	yes

PLIST_FILES=	usr/bin/dbus-binding-tool usr/lib/libdbus-glib-1.so.2 \
		usr/lib/libdbus-glib-1.so.2.1.0
DOCSDIR=	usr/share/doc/dbus-glib-0.76
PORTDOCS=	COPYING ChangeLog NEWS
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>

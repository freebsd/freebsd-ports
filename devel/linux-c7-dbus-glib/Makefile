PORTNAME=	dbus-glib
PORTVERSION=	0.100
DISTVERSIONSUFFIX=	-7.el7
PORTREVISION=	1
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	GLib bindings for D-Bus (Linux CentOS ${LINUX_DIST_VER})

USES=		cpe linux:c7
CPE_VENDOR=	freedesktop
USE_LDCONFIG=	yes
USE_LINUX=	dbuslibs expat
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c6-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>

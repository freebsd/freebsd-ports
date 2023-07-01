PORTNAME=	dbus
PORTVERSION=	1.10.24
DISTVERSIONSUFFIX=	-15.el7
PORTREVISION=	4
CATEGORIES=	devel linux
PKGNAMESUFFIX=	-libs

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Libraries for accessing D-BUS (Linux CentOS ${LINUX_DIST_VER})
WWW=		https://www.freedesktop.org/Software/dbus

LICENSE=	GPLv2+

USES=		cpe linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	expat systemd-libs
USE_LINUX_RPM=	yes
CPE_VENDOR=	freedesktop

LIB_DISTNAMES=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSIONFULL} \
		dbus-glib-0.100-7.el7

SRC_DISTFILES=	${DISTNAME}${SRC_SUFX}:SOURCE \
		dbus-glib-0.100-7.el7${SRC_SUFX}:SOURCE

CONFLICTS=	linux-c6-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>

# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	cairo
PORTVERSION=	1.14.2
PORTREVISION=	2
CATEGORIES=	graphics linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Vector graphics library Cairo (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-f10-${PORTNAME}-[0-9]* linux-c6-${PORTNAME}-[0-9]*

RPMVERSION=	1.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	dri fontconfig pixman png xorglibs
USE_LINUX_RPM=	yes

.include <bsd.port.mk>

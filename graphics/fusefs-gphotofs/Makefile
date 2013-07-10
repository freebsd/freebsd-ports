# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gphotofs
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	graphics sysutils
MASTER_SITES=	SF/gphoto/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mount PTP camera as a file system

LICENSE=	GPLv2

LIB_DEPENDS=	gphoto2:${PORTSDIR}/graphics/libgphoto2

USES=		fuse pkgconfig
USE_BZIP2=	yes
USE_GNOME=	glib20
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/gphotofs

.include <bsd.port.mk>

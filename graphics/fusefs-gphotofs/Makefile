# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gphotofs
PORTVERSION=	0.5
PORTREVISION=	5
CATEGORIES=	graphics sysutils
MASTER_SITES=	SF/gphoto/${PORTNAME}/${PORTVERSION}.0
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Mount PTP camera as a file system

LICENSE=	GPLv2

LIB_DEPENDS=	libgphoto2.so:graphics/libgphoto2

USES=		fuse gnome pkgconfig tar:bzip2
USE_GNOME=	glib20
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/gphotofs

.include <bsd.port.mk>

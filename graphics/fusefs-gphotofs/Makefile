# New ports collection makefile for:	gphotofs
# Date created:				21 June 2006
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gphotofs
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	graphics sysutils
MASTER_SITES=	SF/gphoto/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Mount PTP camera as a file system

LIB_DEPENDS=	fuse.2:${PORTSDIR}/sysutils/fusefs-libs \
		gphoto2.2:${PORTSDIR}/graphics/libgphoto2
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod

USE_BZIP2=	yes
USE_GNOME=	glib20
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/gphotofs

.include <bsd.port.mk>

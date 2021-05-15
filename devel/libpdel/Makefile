# Created by: Archie Cobbs

PORTNAME=	libpdel
PORTVERSION=	0.5.3
PORTREVISION=	6
CATEGORIES=	devel net www
MASTER_SITES=	LOCAL/archie

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Packet Design multi-purpose C library for embedded applications

DEPRECATED=		mastersite disappeared as of 20210515
EXPIRATION_DATE=	2021-08-15
BROKEN_FreeBSD_14=	fails to compile: /usr/include/ufs/ufs/ufsmount.h:99:31: error: field has incomplete type 'struct ufs_extattr_per_mount'

LIB_DEPENDS=	libexpat.so:textproc/expat2

MAKE_ENV=	WITHOUT_PROFILE=yes __MAKE_CONF=/dev/null SRCCONF=/dev/null

USE_LDCONFIG=	yes

.include <bsd.port.mk>

# Created by: bsam
# $FreeBSD$

PORTNAME=	nas-libs
PORTVERSION=	1.9.1
PORTREVISION=	1
CATEGORIES=	audio linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Runtime libraries for NAS (Linux Fedora 10)

USES=		linux:f10
USE_LINUX_RPM=	yes
USE_LINUX=	xorglibs

RPMVERSION=	4.fc9
USE_LDCONFIG=	yes
SRC_DISTFILES=	nas-${PORTVERSION}-${RPMVERSION}.src.rpm:SOURCE

PLIST_FILES=	usr/lib/libaudio.so.2 usr/lib/libaudio.so.2.4
PORTDOCS=	FAQ HISTORY README TODO
DESCR=		${.CURDIR}/../nas/pkg-descr

.include <bsd.port.mk>

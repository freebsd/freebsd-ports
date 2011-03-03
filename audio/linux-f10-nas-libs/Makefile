# New ports collection makefile for:	audio/linux-f10-nas-libs
# Date created:				2009-09-01
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	nas-libs
PORTVERSION=	1.9.1
CATEGORIES=	audio linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Runtime libraries for NAS (Linux Fedora 10)

USE_LINUX_RPM=	yes
USE_LINUX_APPS=	xorglibs
LINUX_DIST_VER=	10
RPMVERSION=	4.fc9
USE_LDCONFIG=	yes
SRC_DISTFILES=	nas-${PORTVERSION}-${RPMVERSION}.src.rpm

PLIST_FILES=	usr/lib/libaudio.so.2 usr/lib/libaudio.so.2.4
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	FAQ HISTORY README TODO
DESCR=		${.CURDIR}/../nas/pkg-descr

.include <bsd.port.mk>

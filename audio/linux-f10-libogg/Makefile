# New ports collection makefile for:	audio/linux-f10-libogg
# Date created:				2009-05-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	libogg
PORTVERSION=	1.1.3
CATEGORIES=	audio linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Ogg bitstream library (Linux Fedora 10)

CONFLICTS=	linux-libogg-[0-9]* linux-f8-libogg-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	10
RPMVERSION=	9.fc9
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libogg.so.0 usr/lib/libogg.so.0.5.3
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	AUTHORS CHANGES COPYING README
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>

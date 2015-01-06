# Created by: bsam
# $FreeBSD$

PORTNAME=	freealut
PORTVERSION=	1.1.0
CATEGORIES=	audio linux
MASTER_SITES=	LOCAL/ehaupt/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Free implementation of OpenAL's ALUT standard (Linux Fedora 10)

CONFLICTS=	linux-freealut-[0-9]* linux-f8-freealut-[0-9]*

USE_LINUX=	f10
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	openal

RPMVERSION=	6.fc9
USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	i386 amd64

PLIST_FILES=	usr/lib/libalut.so.0 usr/lib/libalut.so.0.1.0
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	AUTHORS COPYING ChangeLog README
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>

# Created by: bsam
# $FreeBSD$

PORTNAME=	lib${LINUX_NAME}
PORTVERSION=	0.2.6
CATEGORIES=	audio linux
DISTNAME=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Implementation of the Audio File Library from SGI (Linux Fedora 10)

CONFLICTS=	linux-libaudiofile-[0-9]* linux-f8-libaudiofile-[0-9]*

USES=		linux:f10
USE_LINUX_RPM=	yes
LINUX_NAME=	audiofile

RPMVERSION=	9.fc10
USE_LDCONFIG=	yes
PLIST=		${PKGDIR}/pkg-plist.${LINUX_RPM_ARCH}

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>

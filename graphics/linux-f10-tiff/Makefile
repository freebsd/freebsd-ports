# Created by: bsam
# $FreeBSD$

PORTNAME=	tiff
PORTVERSION=	3.8.2
CATEGORIES=	graphics linux
DISTNAME=	lib${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	TIFF library, Linux/i386 binary (Linux Fedora 10)

USES=		linux:f10
USE_LINUX_RPM=	yes
USE_LINUX=	jpeg

RPMVERSION=	11.fc10
PLIST=		${PKGDIR}/pkg-plist.${LINUX_RPM_ARCH}
USE_LDCONFIG=	yes

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>

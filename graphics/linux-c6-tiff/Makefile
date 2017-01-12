# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	tiff
PORTVERSION=	3.9.4
PORTREVISION=	3
CATEGORIES=	graphics linux
DISTNAME=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	TIFF library (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	BSD3CLAUSE

LINUX_NAME=	lib${PORTNAME}
RPMVERSION=	18.el6_8
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	jpeg
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${LINUX_NAME}-${PORTVERSION}

.include <bsd.port.mk>

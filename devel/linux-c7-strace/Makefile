# $FreeBSD$

PORTNAME=	strace
PORTVERSION=	4.24
DISTVERSIONSUFFIX=	-6.el7
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	System call tracer (CentOS ${LINUX_DIST_VER})

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libdw.so.1:devel/linux-c7-elfutils-libs

USES=		linux:c7
USE_LINUX_RPM=	nolib

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	strace
PORTVERSION=	4.24
DISTVERSIONSUFFIX=	-4.el7
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	System call tracer (CentOS ${LINUX_DIST_VER})

RUN_DEPENDS=	/compat/linux/usr/lib64/libdw.so.1:devel/linux-c7-elfutils-libs

USES=		linux:c7
USE_LINUX_RPM=	nolib

.include <bsd.port.mk>

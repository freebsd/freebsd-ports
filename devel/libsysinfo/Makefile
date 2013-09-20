# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	libsysinfo
PORTVERSION=	0.0.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	jwbacon@tds.net
COMMENT=	GNU libc's sysinfo port for FreeBSD

LICENSE=	BSD

USE_LDCONFIG=	yes
PROJECTHOST=	sysinfo-bsd

LDFLAGS+=	-lkvm

PLIST_FILES=	include/sys/sysinfo.h \
	lib/libsysinfo.a \
	lib/libsysinfo.so \
	lib/libsysinfo.so.0
PLIST_DIRSTRY=	include/sys

MAN3=		sysinfo.3

NO_STAGE=	yes
.include <bsd.port.mk>

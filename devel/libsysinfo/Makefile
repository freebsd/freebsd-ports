# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	libsysinfo
PORTVERSION=	0.0.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	jwbacon@tds.net
COMMENT=	GNU libc's sysinfo port for FreeBSD

LICENSE=	BSD3CLAUSE

USES=		uidfix
USE_LDCONFIG=	yes
PROJECTHOST=	sysinfo-bsd

LDFLAGS+=	-lkvm

PLIST_FILES=	include/sys/sysinfo.h \
		lib/libsysinfo.a \
		lib/libsysinfo.so \
		lib/libsysinfo.so.0 \
		man/man3/sysinfo.3.gz

.include <bsd.port.mk>

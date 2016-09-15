# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	libsysinfo
PORTVERSION=	0.0.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	bacon4000@gmail.com
COMMENT=	GNU libc's sysinfo port for FreeBSD

LICENSE=	BSD3CLAUSE

BROKEN=		Unfetchable (google code has gone away)

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

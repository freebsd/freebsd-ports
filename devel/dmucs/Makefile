# Created by: Max Khon <fjoe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dmucs
PORTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Distributed Multi-User Compilation System (for use with distcc)

BROKEN_armv6=		fails to compile: passing char * to parameter of incompatible type __builtin_va_list
BROKEN_armv7=		fails to compile: passing char * to parameter of incompatible type __builtin_va_list
BROKEN_aarch64=		fails to compile: passing char * to parameter of incompatible type __builtin_va_list

WRKSRC=		${WRKDIR}/${PORTNAME}
USES=	tar:bzip2
GNU_CONFIGURE=	yes
PLIST_FILES=	bin/dmucs bin/gethost bin/loadavg bin/monitor bin/remhost

.include <bsd.port.mk>

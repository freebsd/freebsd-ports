# New ports collection makefile for:	libsysinfo
# Date created:		14 April 2012
# Whom:			Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	libsysinfo
PORTVERSION=	0.0.2
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	jwbacon@tds.net
COMMENT=	GNU libc's sysinfo port for FreeBSD

LICENSE=	BSD

USE_LDCONFIG=	yes
PROJECTHOST=	sysinfo-bsd

PLIST_FILES=	include/sys/sysinfo.h \
	lib/libsysinfo.a \
	lib/libsysinfo.so \
	lib/libsysinfo.so.0
PLIST_DIRSTRY=	include/sys

MAN3=		sysinfo.3

.include <bsd.port.mk>

# New ports collection makefile for:    linux_kdump
# Version required:	1
# Date created:         Nov 26 1997
# Whom:                 msmith@FreeBSD.org
#
# $Id$
#

DISTNAME=	linux_kdump-1.0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gsoft.com.au/misc/

MAINTAINER=	msmith@FreeBSD.org

BUILD_DEPENDS=	/compat/linux/usr/bin/cpp:${PORTSDIR}/devel/linux_devel

.if !exists(/sys/i386/linux/syscalls.master)
BROKEN=		"requires kernel source present in /sys"
.endif
.if !exists(/usr/src/usr.bin/ktrace/subr.c)
BROKEN=		"requires ktrace source present in /usr/src/usr.bin/ktrace"
.endif

.include <bsd.port.mk>

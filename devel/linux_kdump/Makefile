# New ports collection makefile for:    linux_kdump
# Version required:	1
# Date created:         Nov 26 1997
# Whom:                 msmith@FreeBSD.org
#
# $Id: Makefile,v 1.4 1998/12/19 10:41:23 dfr Exp $
#

DISTNAME=	linux_kdump-1.0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gsoft.com.au/misc/

MAINTAINER=	msmith@FreeBSD.org

BUILD_DEPENDS=	/compat/linux/usr/bin/cpp:${PORTSDIR}/devel/linux_devel

ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

.if !exists(/sys/i386/linux/syscalls.master)
BROKEN=		"requires kernel source present in /sys"
.endif
.if !exists(/usr/src/usr.bin/ktrace/subr.c)
BROKEN=		"requires ktrace source present in /usr/src/usr.bin/ktrace"
.endif

.include <bsd.port.post.mk>

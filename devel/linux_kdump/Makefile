# New ports collection makefile for:    linux_kdump
# Version required:	1.2
# Date created:         Nov 26 1997
# Whom:                 msmith@FreeBSD.org
#
# $FreeBSD$
#

DISTNAME=	linux_kdump-1.4
CATEGORIES=	devel
MASTER_SITES=	http://www.FreeBSD.org/~marcel/			\
		ftp://ftp.scc.nl/pub/FreeBSD/distfiles/

MAINTAINER=	marcel@FreeBSD.org

BUILD_DEPENDS=	/compat/linux/usr/bin/gcc:${PORTSDIR}/devel/linux_devtools

ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

.if !exists(/sys/i386/linux/syscalls.master)
BROKEN=		"requires kernel source present in /sys"
.endif
.if !exists(/usr/src/usr.bin/ktrace/subr.c)
BROKEN=		"requires ktrace source present in /usr/src/usr.bin/ktrace"
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:    linux_kdump
# Date created:         Nov 26 1997
# Whom:                 msmith@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	linux_kdump
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	devel linux
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	marcel

MAINTAINER=	marcel@FreeBSD.org
COMMENT=	Linux-compatability ktrace.out processor

BUILD_DEPENDS=	/compat/linux/usr/bin/gcc:${PORTSDIR}/devel/linux_devtools-7

ONLY_FOR_ARCHS=	i386
MAN1=		linux_kdump.1
PLIST_FILES=	bin/linux_kdump

.include <bsd.port.pre.mk>

.ifndef(SRCDIR)
SRCDIR=		/usr/src
pre-everything::
	@${ECHO_MSG} '===> Using the FreeBSD source tree under /usr/src'
	@${ECHO_MSG} '===> Set SRCDIR to use an alternate source tree'
.endif

.if !exists(${SRCDIR}/sys/i386/linux/syscalls.master)
IGNORE=		"requires kernel source present in ${SRCDIR}/sys"
.endif
.if !exists(${SRCDIR}/usr.bin/ktrace/subr.c)
IGNORE=		"requires ktrace source present in ${SRCDIR}/usr.bin/ktrace"
.endif

.include <bsd.port.post.mk>

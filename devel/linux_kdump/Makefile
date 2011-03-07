# New ports collection makefile for:    linux_kdump
# Date created:         Nov 26 1997
# Whom:                 msmith@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	linux_kdump
PORTVERSION=	1.5
PORTREVISION=	2
CATEGORIES=	devel linux
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	marcel

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Linux-compatibility ktrace.out processor

BUILD_DEPENDS=	${LINUXBASE}/usr/bin/gcc:${PORTSDIR}/emulators/linux_base-gentoo-stage3

ONLY_FOR_ARCHS=	i386 amd64
NO_MANCOMPRESS=	yes
MAN1=		linux_kdump.1.gz
PLIST_FILES=	bin/linux_kdump

.include <bsd.port.pre.mk>

pre-everything::
	@${ECHO_MSG} '===> Using the FreeBSD source tree under ${SRC_BASE}'
	@${ECHO_MSG} '===> Set SRC_BASE to use an alternate source tree'

.if !exists(${SRC_BASE}/sys/i386/linux/syscalls.master)
IGNORE=	requires kernel source present in ${SRC_BASE}/sys
.endif
.if !exists(${SRC_BASE}/usr.bin/ktrace/subr.c)
IGNORE=	requires ktrace source present in ${SRC_BASE}/usr.bin/ktrace
.endif
.if exists(${LINUXBASE}/etc/fedora-release)
IGNORE=	does not build with the default linux base, use the package instead
.endif

.include <bsd.port.post.mk>

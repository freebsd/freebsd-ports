# Created by: msmith@FreeBSD.org
# $FreeBSD$

PORTNAME=	linux_kdump
PORTVERSION=	1.5
PORTREVISION=	2
CATEGORIES=	devel linux
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	marcel

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Linux-compatibility ktrace.out processor

BROKEN=		Fails to build with new linux_base-gentoo-stage3

BUILD_DEPENDS=	${LINUXBASE}/usr/bin/gcc:${PORTSDIR}/emulators/linux_base-gentoo-stage3

USES=		uidfix
ONLY_FOR_ARCHS=	i386 amd64
NO_MANCOMPRESS=	yes
PLIST_FILES=	bin/linux_kdump man/man1/linux_kdump.1.gz

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

pre-install:
	${MKDIR} ${STAGEDIR}/bin ${STAGEDIR}/man/man1

post-install:
	${MV} -i ${STAGEDIR}/bin/linux_kdump ${STAGEDIR}/${PREFIX}/bin
	${MV} -i ${STAGEDIR}/man/man1/linux_kdump.1.gz ${STAGEDIR}/${PREFIX}/man/man1
	${RMDIR} ${STAGEDIR}/bin ${STAGEDIR}/man/man1 ${STAGEDIR}/man

.include <bsd.port.post.mk>

# New ports collection makefile for:	kqemu-kmod
# Date created:				2005/10/25
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	kqemu
PORTVERSION=	0.7.2
CATEGORIES=	emulators
MASTER_SITES=	http://fabrice.bellard.free.fr/qemu/
PKGNAMESUFFIX=	-kmod
DIST_SUBDIR=	kqemu

MAINTAINER=	nork@FreeBSD.org
COMMENT=	Kernel Acceralator for QEMU CPU Emulator

ONLY_FOR_ARCHS=	i386 amd64
NO_PACKAGE=	"Depends on kernel, and module not redistributable"

PLIST_FILES=	"include/kqemu/kqemu.h"
PLIST_FILES+=	"@dirrm include/kqemu"
PLIST_FILES+=	"@cwd /"
PLIST_FILES+=	${KMODDIR:C,^/,,}/kqemu.ko

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKEFILE=	Makefile.freebsd

.include <bsd.port.pre.mk>

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		kqemu requires kernel source to be installed
.endif

post-install:
	@${MKDIR} ${PREFIX}/include/kqemu
	@${INSTALL_DATA} ${WRKSRC}/kqemu.h ${PREFIX}/include/kqemu
	if mount |${GREP} ^devfs >/dev/null ; then \
		: ; \
	else \
		if [ ! -e /dev/kqemu ]; then\
			mknod /dev/kqemu c 250 0 ; \
		fi ; \
		${CHMOD} 666 /dev/kqemu ; \
	fi

.include <bsd.port.post.mk>

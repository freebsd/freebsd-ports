# New ports collection makefile for:	kqemu-kmod
# Date created:				2005/10/25
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	kqemu
PORTVERSION=	1.3.0.p7
CATEGORIES=	emulators
MASTER_SITES=	http://fabrice.bellard.free.fr/qemu/
PKGNAMESUFFIX=	-kmod
DISTNAME=	${PORTNAME}-${PORTVERSION:C/.p/pre/}
DIST_SUBDIR=	kqemu

MAINTAINER=	nox@jelal.kn-bremen.de
COMMENT=	Kernel Acceralator for QEMU CPU Emulator (development version)

ONLY_FOR_ARCHS=	i386 amd64
NO_PACKAGE=	Depends on kernel, and module not redistributable

PLIST_FILES=	"include/kqemu/kqemu.h"
PLIST_FILES+=	"@dirrm include/kqemu"
PLIST_FILES+=	"@cwd /"
PLIST_FILES+=	${KMODDIR:C,^/,,}/kqemu.ko

MAKEFILE=	Makefile.freebsd

.include <bsd.port.pre.mk>
MAKE_ENV+=	KMODDIR="${KMODDIR}"

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

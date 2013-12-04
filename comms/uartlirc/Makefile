# Created by: nox@FreeBSD.org
# $FreeBSD$

PORTNAME=	uartlirc
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	comms kld
MASTER_SITES=	LOCAL/nox \
		http://people.freebsd.org/~nox/tmp/
DISTNAME=	${PORTNAME}-preliminary-003
EXTRACT_SUFX=	.shar

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Driver for "homebrew" serial LIRC receivers

SSP_UNSAFE=	kernel module does not support ssp

WRKSRC=		${WRKDIR}/${PORTNAME}
EXTRACT_CMD=	${SH}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=

NO_STAGE=	yes
.include <bsd.port.pre.mk>

PLIST_FILES+=	"@cwd /"
PLIST_FILES+=	${KMODDIR:C,^/,,}/${PORTNAME}.ko
PLIST_FILES+=	"@exec kldxref ${KMODDIR}"
PLIST_FILES+=	"@unexec kldxref ${KMODDIR}"

# install where x11/nvidia-driver does also:
KMODDIR=	/boot/modules

MAKE_ENV+=	KMODDIR="${KMODDIR}"

SYSDIR?=	${SRC_BASE}/sys
MAKE_ENV+=	SYSDIR="${SYSDIR}"

CFLAGS+=	${DEBUG_FLAGS}

.if ${OSVERSION} < 800000
IGNORE=		needs <sys/buf_ring.h>
.endif

.if !exists(${SYSDIR}/Makefile)
IGNORE=		requires kernel source to be installed
.endif

.if ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on powerpc or sparc64
.endif

do-install:
	${INSTALL} ${WRKSRC}/${PORTNAME}.ko ${KMODDIR}
	kldxref ${KMODDIR}

.include <bsd.port.post.mk>

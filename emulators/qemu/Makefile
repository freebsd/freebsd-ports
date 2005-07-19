# New ports collection makefile for:	qemu
# Date created:			2004/05/31
# Whom:				Juergen Lock <nox@jelal.kn-bremen.de>
#
# $FreeBSD$
#

PORTNAME=	qemu
PORTVERSION=	0.7.0s.20050717
CATEGORIES=	emulators
MASTER_SITES=	http://www.qemu.org/ \
		http://people.fruitsalad.org/nox/qemu/ \
		http://dad-answers.com/qemu/
DISTNAME=	${PORTNAME}-snapshot-2005-07-17_23
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	nox@jelal.kn-bremen.de
COMMENT=	QEMU CPU Emulator

BUILD_DEPENDS+=	texi2html:${PORTSDIR}/textproc/texi2html
.if defined(WITH_SAMBA)
RUN_DEPENDS+=	${LOCALBASE}/sbin/smbd:${PORTSDIR}/net/samba
.endif

.if defined(WITH_KQEMU)
DISTKQEMU=	kqemu-0.6.2-1.tar.gz
DISTFILES=	${EXTRACT_ONLY} ${DISTKQEMU}
.endif

HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETOPT_LONG=	yes
USE_SDL=	sdl
USE_PERL5=	yes
PATCH_STRIP=	-p1
CONFIGURE_ARGS+=	--prefix=${PREFIX} --cc=${CC}
MAKE_ENV+=	BSD_MAKE=${MAKE}
MAN1=		qemu.1 qemu-img.1
ONLY_FOR_ARCHS=	amd64 i386
.if defined(WITH_KQEMU)
NO_PACKAGE=	Depends on kernel, and module not redistributable
PLIST_SUB=	WITH_KQEMU=""
PLIST_SUB+=	KMODDIR=${KMODDIR}
.else
PLIST_SUB=	WITH_KQEMU="@comment "
.endif

# gcc34 (system cc on 5.x now) has problems with qemu on amd64
# (doesnt build target-i386/op.c), try the one in ports which is newer
.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
ARCH=		x86_64
.if ${OSVERSION} >= 502126
BUILD_DEPENDS+=	gcc34:${PORTSDIR}/lang/gcc34
GCCVERSION=	030402
CC=		gcc34
.else
USE_GCC=	3.4
.endif
.else
USE_GCC=	3.4
.endif

.if defined(WITH_KQEMU) && ${ARCH} != "i386"
IGNORE=		kqemu only supported on i386
.endif

.if defined(WITH_KQEMU) && !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		kqemu requires kernel source to be installed
.endif

pre-everything::
.if !defined(WITH_KQEMU) && ${ARCH} == "i386"
	@${ECHO_MSG} "Notice: you can build qemu with the (alpha!) kqemu accelerator kernel module"
	@${ECHO_MSG} "by defining WITH_KQEMU."
.endif
.if !defined(WITH_SAMBA) && !exists(${LOCALBASE}/sbin/smbd)
	@${ECHO_MSG} "Notice: if you need qemu's -smb option (smb-export local dir to guest)"
	@${ECHO_MSG} "then you also need samba, you can have this port install it by defining"
	@${ECHO_MSG} "WITH_SAMBA."
.endif

.if defined(WITH_KQEMU)
post-extract:
	@cd ${WRKSRC} && ${TAR} xfz ${_DISTDIR}/${DISTKQEMU}
	@${CP} ${FILESDIR}/BSDmakefile ${FILESDIR}/kmod_bsd.c ${WRKSRC}/kqemu
.endif

pre-patch:
	@for A in ${ONLY_FOR_ARCHS}; do \
		${MKDIR} ${WRKSRC}/bsd/$$A; \
	done

post-install:
.if defined(WITH_KQEMU)
	${INSTALL_SCRIPT} ${WRKSRC}/kqemu/kqemu.ko ${KMODDIR}
	if mount |${GREP} ^devfs >/dev/null ; then \
		: ; \
	else \
		if [ ! -e /dev/kqemu ]; then\
			mknod /dev/kqemu c 250 0 ; \
		fi ; \
		${CHMOD} 666 /dev/kqemu ; \
	fi
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

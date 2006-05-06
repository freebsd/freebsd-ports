# New ports collection makefile for:	qemu
# Date created:			2004/05/31
# Whom:				Juergen Lock <nox@jelal.kn-bremen.de>
#
# $FreeBSD$
#

PORTNAME=	qemu
PORTVERSION=	0.8.1
CATEGORIES=	emulators
MASTER_SITES=	http://www.qemu.org/:release \
		http://people.fruitsalad.org/nox/qemu/:snapshot \
		http://www.volny.cz/xnavara/qemu/:snapshot \
		http://qemu.dad-answers.com/download/qemu/:snapshot \
		http://people.brandeis.edu/~jcoiner/qemu_idedma/:idedma \
		http://people.freebsd.org/~maho/qemu/:misc
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:release
.if defined (WITH_HACKS_CIRRUS) || defined (WITH_HACKS)
DISTFILES+=	patch3_cirrus:misc
.endif
DIST_SUBDIR=	qemu
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	nox@jelal.kn-bremen.de
COMMENT=	QEMU CPU Emulator

BUILD_DEPENDS+=	texi2html:${PORTSDIR}/textproc/texi2html
.if defined(WITH_SAMBA)
RUN_DEPENDS+=	${LOCALBASE}/sbin/smbd:${PORTSDIR}/net/samba
.endif
.if defined(WITH_KQEMU)
BUILD_DEPENDS+=	kqemu-kmod>=1.3.0pre5:${PORTSDIR}/emulators/kqemu-kmod
.endif

HAS_CONFIGURE=	yes
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
CONFIGURE_ARGS+=	--enable-kqemu
.else
CONFIGURE_ARGS+=	--disable-kqemu
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
MAKE_ARGS+=	ARCH=x86_64
.endif
USE_GCC=	3.4

pre-everything::
.if !defined(WITH_KQEMU)
	@${ECHO_MSG} "Notice: you can build qemu with the (alpha!) kqemu accelerator kernel module"
	@${ECHO_MSG} "by defining WITH_KQEMU."
.endif
.if !defined(WITH_HACKS_CIRRUS) && !defined(WITH_HACKS)
	@${ECHO_MSG} "You can build qemu with some hacks (esp. for speedup)"
	@${ECHO_MSG} "by defining WITH_HACKS, or specifically:"
	@${ECHO_MSG} "2. WITH_HACKS_CIRRUS: higher speed on large display (cirrus_vga)"
	@${ECHO_MSG} "by Juergen Pfennig"
	@${ECHO_MSG} "http://lists.gnu.org/archive/html/qemu-devel/2006-01/msg00208.html"
	@${ECHO_MSG} "Note: this second patch is known to cause mouse problems with some(?)"
	@${ECHO_MSG} "versions of XP, and also minor redraw bugs with some Linux guests."
.endif
.if !defined(WITH_SAMBA) && !exists(${LOCALBASE}/sbin/smbd)
	@${ECHO_MSG} "Notice: if you need qemu's -smb option (smb-export local dir to guest)"
	@${ECHO_MSG} "then you also need samba, you can have this port install it by defining"
	@${ECHO_MSG} "WITH_SAMBA."
.endif

post-extract:
	@${MKDIR} ${WRKSRC}/kqemu
	@${TOUCH} ${WRKSRC}/kqemu/Makefile
	@${ECHO} all: > ${WRKSRC}/kqemu/Makefile.freebsd

pre-patch:
	@for A in ${ONLY_FOR_ARCHS}; do \
		${MKDIR} ${WRKSRC}/bsd/$$A; \
	done

post-patch:
.if defined(WITH_HACKS_CIRRUS) || defined (WITH_HACKS)
	@cd ${WRKSRC} ; ${PATCH} --quiet < ${DISTDIR}/${DIST_SUBDIR}/patch3_cirrus
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

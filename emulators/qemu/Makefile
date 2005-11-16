# New ports collection makefile for:	qemu
# Date created:			2004/05/31
# Whom:				Juergen Lock <nox@jelal.kn-bremen.de>
#
# $FreeBSD$
#

PORTNAME=	qemu
PORTVERSION=	0.7.2s.20051112
PORTREVISION=	0
CATEGORIES=	emulators
MASTER_SITES=	http://www.qemu.org/:release \
		http://people.fruitsalad.org/nox/qemu/:snapshot \
		http://www.volny.cz/xnavara/qemu/:snapshot \
		http://qemu.dad-answers.com/download/qemu/:snapshot
DISTNAME=	${PORTNAME}-snapshot-2005-11-12_23
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:snapshot

MAINTAINER=	nox@jelal.kn-bremen.de
COMMENT=	QEMU CPU Emulator

BUILD_DEPENDS+=	texi2html:${PORTSDIR}/textproc/texi2html
.if defined(WITH_SAMBA)
RUN_DEPENDS+=	${LOCALBASE}/sbin/smbd:${PORTSDIR}/net/samba
.endif
.if defined(WITH_KQEMU)
BUILD_DEPENDS+=	${LOCALBASE}/include/kqemu/kqemu.h:${PORTSDIR}/emulators/kqemu-kmod
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

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

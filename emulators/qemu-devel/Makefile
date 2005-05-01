# New ports collection makefile for:	qemu
# Date created:			2004/05/31
# Whom:				Juergen Lock <nox@jelal.kn-bremen.de>
#
# $FreeBSD$
#

PORTNAME=	qemu
PORTVERSION=	0.7.0
CATEGORIES=	emulators
MASTER_SITES=	http://www.qemu.org/

MAINTAINER=	nox@jelal.kn-bremen.de
COMMENT=	QEMU CPU Emulator

BUILD_DEPENDS+=	texi2html:${PORTSDIR}/textproc/texi2html
.if defined(WITH_SAMBA)
RUN_DEPENDS+=	${LOCALBASE}/sbin/smbd:${PORTSDIR}/net/samba
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

pre-everything::
.if !defined(WITH_SAMBA) && !exists(${LOCALBASE}/sbin/smbd)
	@${ECHO_MSG} "Notice: if you need qemu's -smb option (smb-export local dir to guest)"
	@${ECHO_MSG} "then you also need samba, you can have this port install it by defining"
	@${ECHO_MSG} "WITH_SAMBA."
.endif

pre-patch:
	@for A in ${ONLY_FOR_ARCHS}; do \
		${MKDIR} ${WRKSRC}/bsd/$$A; \
	done

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

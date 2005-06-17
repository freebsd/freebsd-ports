# New ports collection makefile for:	GNU Pth
# Date Created:				23 May 1999
# Whom:					Ralf S. Engelschall <rse@gnu.org>
#
# $FreeBSD$
#

PORTNAME=	pth
PORTVERSION=	2.0.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	pth

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Portable Threads

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/pth
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS= --enable-optimize \
		--enable-batch \
		--includedir="${PREFIX}/include/pth" \
		--libdir="${PREFIX}/lib/pth"

USE_REINPLACE=	yes

MAN1=		pth-config.1 pthread-config.1
MAN3=		pth.3 pthread.3

OPTIONS=	OPTIMIZED_CFLAGS "Build with optimized CFLAGS" on \
		SYSCALL_HARD "Build with hard syscalls" off


#OPTIONS+=	SYSCALL_SOFT_DISABLED "Disable soft syscalls" off \
#		SYSCALL_SOFT "Disable soft syscalls" on

.include <bsd.port.pre.mk>

.if defined(WITH_SYSCALL_HARD)
CONFIGURE_ARGS+= --enable-syscall-hard --disable-syscall-soft
.else
CONFIGURE_ARGS+= --enable-syscall-soft
CONFIGURE_ARGS+= --enable-pthread
.endif

#.if defined(WITH_SYSCALL_SOFT_DISABLED)
#CONFIGURE_ARGS+= --disable-syscall-soft
#.else
#CONFIGURE_ARGS+= --enable-syscall-soft
#.endif

post-patch:
.if defined(WITHOUT_OPTIMIZED_CFLAGS)
	@${REINPLACE_CMD} -e \
		's|-funroll-loops -fstrength-reduce -fomit-frame-pointer -ffast-math||' \
		${WRKSRC}/configure
.endif

post-build:
	@${ECHO_MSG} "===>  Use 'make test' to run a quick test suite."

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/pth.sh ${PREFIX}/etc/rc.d/000.pth.sh

test:
	@cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.post.mk>

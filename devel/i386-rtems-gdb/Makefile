# New ports collection makefile for:	i386-rtems-gdb
# Date created:		9 June 2000
# Whom:			James Housley <jim@thehousleys.net>
#
# $FreeBSD$
#

PORTNAME=	gdb
PORTVERSION=	5.2
PORTREVISION=	11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gdb

MAINTAINER=	jeh@FreeBSD.org
COMMENT=	FSF gdb-5.2 base-port for RTEMS development

PATCHFILES=	${GDBNAME}-rtems-base-20020612.diff \
		${GDBNAME}-rtems-cg-20020612.diff \
		${GDBNAME}-rtems-rdbg-20020612.diff
PATCH_SITES=	ftp://ftp.rtems.com/pub/rtems/snapshots/c_tools/source/ \
		http://rtems.thehousleys.net/

.include <bsd.port.pre.mk>

LCLTARGET?=	i386-rtems

GDBNAME=	gdb-5.2
PLIST=		${PKGDIR}/pkg-plist.${LCLTARGET}

BUILD_DEPENDS=	${LCLTARGET}-as:${PORTSDIR}/devel/${LCLTARGET}-binutils \
		${LCLTARGET}-ld:${PORTSDIR}/devel/${LCLTARGET}-binutils
RUN_DEPENDS=	${LCLTARGET}-as:${PORTSDIR}/devel/${LCLTARGET}-binutils \
		${LCLTARGET}-ld:${PORTSDIR}/devel/${LCLTARGET}-binutils

PKGNAMEPREFIX=	${LCLTARGET}-
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	all info

CONFIGURE_TARGET?=	--target=${LCLTARGET}
CONFIGURE_ARGS?=	--verbose
CONFIGURE_WRKSRC?=	${WRKDIR}/build-${LCLTARGET}
CONFIGURE_SCRIPT?=	../${GDBNAME}/configure

PATCH_DIST_STRIP?=	-p1

# Need to patch a patch file
.if ${LCLTARGET} == powerpc-rtems
PATCHFILES+=	powerpc-gdb-5.2-hw_sem.c.diff:THN \
		powerpc-gdb-5.2-hw_shm.c.diff:THN \
		powerpc-gdb-5.2-ppc-ppc-instructions.diff:THN \
		powerpc-gdb-5.2-gdb-remote-sds.c.diff:THN
PATCH_SITES+=	http://rtems.thehousleys.net/:THN
.endif

# Need to patch a patch file
.if ${LCLTARGET} == i960-rtems
PATCHFILES+=	i960-gdb-5.2-sem-switch.c.diff:THN
PATCH_SITES+=	http://rtems.thehousleys.net/:THN
.endif

# Need to patch a patch file
.if ${LCLTARGET} == arm-rtems
PATCHFILES+=	arm-gdb-gdb-5.2-gdb-arm-tdep.c.diff:THN
PATCH_SITES+=	http://rtems.thehousleys.net/:THN
.endif

.if ${LCLTARGET} == sparc-rtems
.if ${OSVERSION} >= 502000
CONFIGURE_ARGS+=	--verbose --disable-sim
PLIST_SUB+=		SPARC_NOSIM='@comment '
.else
CONFIGURE_ARGS+=	--verbose --enable-sim
PLIST_SUB+=		SPARC_NOSIM=''
MAN1=		${LCLTARGET}-run.1
.endif
.endif

MAN1+=		${LCLTARGET}-gdb.1

pre-configure:
	@(cd ${WRKDIR} ; ${MKDIR} build-${LCLTARGET})

do-build:
	@(cd ${WRKDIR}/build-${LCLTARGET} ; \
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

do-install:
	@(cd ${WRKDIR}/build-${LCLTARGET} && \
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

.include <bsd.port.post.mk>

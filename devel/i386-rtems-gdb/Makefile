# New ports collection makefile for:	i386-rtems-gdb
# Date created:		9 June 2000
# Whom:			James Housley <jim@thehousleys.net>
#
# $FreeBSD$
#

PORTNAME=	gdb
PORTVERSION=	4.18
CATEGORIES=	devel
MASTER_SITES=   ftp://ftp.oarcorp.com/pub/rtems/betas/rtems-4.5.0-beta/c_tools/source/ \
		http://www.thehousleys.net/rtems-4.5.0b3/
PATCHFILES=	${GDBNAME}-rtems-20000524.diff.gz
PATCH_SITES=	ftp://ftp.oarcorp.com/pub/rtems/betas/rtems-4.5.0-beta/c_tools/source/ \
		http://www.thehousleys.net/rtems-4.5.0b3/

MAINTAINER=	jim@thehousleys.net

DIST_SUBDIR=	rtems

LCLTARGET?=	i386-rtems

GDBNAME=	gdb-4.18
MASTERDIR=	${.CURDIR}/../i386-rtems-gdb
PLIST=		${PKGDIR}/PLIST.${LCLTARGET}

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

MAN1=		${LCLTARGET}-gdb.1
MAN3=		readline.3

.if defined(PATCH_DEBUG)
PATCH_DIST_ARGS=   -d ${WRKDIR} -E ${PATCH_DIST_STRIP}
.else
PATCH_DIST_ARGS=   -d ${WRKDIR} --forward --quiet -E ${PATCH_DIST_STRIP}
.endif

pre-configure:
	@(cd ${WRKDIR} ; ${MKDIR} build-${LCLTARGET})

do-build:
	@(cd ${WRKDIR}/build-${LCLTARGET} ; \
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

do-install:
	@(cd ${WRKDIR}/build-${LCLTARGET} && \
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

post-install:
	@install-info ${PREFIX}/info/readline.info ${PREFIX}/info/dir
	@install-info ${PREFIX}/info/history.info ${PREFIX}/info/dir

.include <bsd.port.mk>

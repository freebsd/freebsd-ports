# New ports collection makefile for:	i386-rtems-binutils
# Date created:		9 June 2000
# Whom:			James Housley <jim@thehousleys.net>
#
# $FreeBSD$
#

PORTNAME=	binutils
PORTVERSION=	2.9.5.0.24
CATEGORIES=	devel
MASTER_SITES=   ftp://ftp.oarcorp.com/pub/rtems/betas/rtems-4.5.0-beta/c_tools/source/ \
		http://www.thehousleys.net/rtems-4.5.0b3/
PATCHFILES=	${BINNAME}-rtems-20000207.diff.gz
PATCH_SITES=	ftp://ftp.oarcorp.com/pub/rtems/betas/rtems-4.5.0-beta/c_tools/source/ \
		http://www.thehousleys.net/rtems-4.5.0b3/

MAINTAINER=	jim@thehousleys.net

DIST_SUBDIR=	rtems

LCLTARGET?=	i386-rtems

BINNAME=	binutils-2.9.5.0.24
MASTERDIR=	${.CURDIR}/../i386-rtems-binutils
PLIST=		${PKGDIR}/PLIST.${LCLTARGET}

PKGNAMEPREFIX=	${LCLTARGET}-
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	all info

CONFIGURE_TARGET?=	--target=${LCLTARGET}
CONFIGURE_ARGS?=	--verbose
CONFIGURE_WRKSRC?=	${WRKDIR}/build-${LCLTARGET}
CONFIGURE_SCRIPT?=	../${BINNAME}/configure

MAN1=		${LCLTARGET}-ar.1 ${LCLTARGET}-nm.1 ${LCLTARGET}-objdump.1 \
		${LCLTARGET}-ranlib.1 ${LCLTARGET}-size.1 \
		${LCLTARGET}-strings.1 ${LCLTARGET}-strip.1 \
		${LCLTARGET}-objcopy.1 ${LCLTARGET}-addr2line.1 \
		${LCLTARGET}-nlmconv.1 ${LCLTARGET}-c++filt.1 \
		${LCLTARGET}-as.1 ${LCLTARGET}-ld.1

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

.include <bsd.port.mk>

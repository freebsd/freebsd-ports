# New ports collection makefile for:	i386-rtems-g77
# Date created:		9 June 2000
# Whom:			James Housley <jim@thehousleys.net>
#
# $FreeBSD$
#

PORTNAME=	g77
PORTVERSION=	2.95.2
PORTREVISION=	9
CATEGORIES=	devel
MASTER_SITES=   ftp://ftp.oarcorp.com/pub/rtems/snapshots/c_tools/source/ \
		http://rtems.thehousleys.net/
DISTFILES=	${F77NAME}.tar.gz ${NEWLIBNAME}.tar.gz
PATCHFILES=	${F77NAME}-rtems-20000724.diff.gz \
		${NEWLIBNAME}-rtems-20000828.diff.gz
PATCH_SITES=	ftp://ftp.oarcorp.com/pub/rtems/snapshots/c_tools/source/ \
		http://rtems.thehousleys.net/

MAINTAINER=	jim@thehousleys.net

DIST_SUBDIR=	rtems

LCLTARGET?=	i386-rtems

F77NAME=	gcc-2.95.2
NEWLIBNAME=	newlib-1.8.2
MASTERDIR=	${.CURDIR}/../i386-rtems-g77
PLIST=		${PKGDIR}/PLIST.${LCLTARGET}

BUILD_DEPENDS=	autoheader:${PORTSDIR}/devel/autoconf \
		${LCLTARGET}-gcc:${PORTSDIR}/devel/${LCLTARGET}-gcc
RUN_DEPENDS=	${LCLTARGET}-gcc:${PORTSDIR}/devel/${LCLTARGET}-gcc

PKGNAMEPREFIX=	${LCLTARGET}-
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	all

CONFIGURE_TARGET?=	--target=${LCLTARGET}
CONFIGURE_ARGS?=	--with-gnu-as --with-gnu-ld --with-newlib --verbose \
			--enable-languages="f77"
CONFIGURE_WRKSRC?=	${WRKDIR}/build-${LCLTARGET}
CONFIGURE_SCRIPT?=	../${F77NAME}/configure

MAKE_FLAGS=	LANGUAGES="f77"

.if defined(PATCH_DEBUG)
PATCH_DEBUG_TMP=	yes
PATCH_ARGS=		-d ${WRKDIR}/${F77NAME} -E ${PATCH_STRIP}
PATCH_DIST_ARGS=	-d ${WRKDIR} -E ${PATCH_DIST_STRIP}
.else
PATCH_DEBUG_TMP=	no
PATCH_ARGS=		-d ${WRKDIR}/${F77NAME} --forward --quiet -E ${PATCH_STRIP}
PATCH_DIST_ARGS=	-d ${WRKDIR} --forward --quiet -E ${PATCH_DIST_STRIP}
.endif

pre-configure:
	@(cd ${WRKDIR} ; \
	cd ${F77NAME} ; ${LN} -fs ../${NEWLIBNAME}/newlib . ; \
	cd .. ; \
	${MKDIR} build-${LCLTARGET})

do-build:
	@(cd ${WRKDIR}/build-${LCLTARGET} ; \
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

do-install:
	@(cd ${WRKDIR}/build-${LCLTARGET} && \
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

.include <bsd.port.mk>

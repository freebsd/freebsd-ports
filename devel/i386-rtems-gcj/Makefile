# New ports collection makefile for:	i386-rtems-gcj
# Date created:		9 June 2000
# Whom:			James Housley <jim@thehousleys.net>
#
# $FreeBSD$
#

PORTNAME=	gcj
PORTVERSION=	2.95.2
CATEGORIES=	devel
MASTER_SITES=   ftp://ftp.oarcorp.com/pub/rtems/betas/rtems-4.5.0-beta/c_tools/source/ \
		http://www.thehousleys.net/rtems-4.5.0b3/
DISTFILES=	${JAVANAME}.tar.gz ${NEWLIBNAME}.tar.gz
PATCHFILES=	${JAVANAME}-rtems-20000531.diff.gz \
		${NEWLIBNAME}-rtems-20000606.diff.gz
PATCH_SITES=	ftp://ftp.oarcorp.com/pub/rtems/betas/rtems-4.5.0-beta/c_tools/source/ \
		http://www.thehousleys.net/rtems-4.5.0b3/

MAINTAINER=	jim@thehousleys.net

DIST_SUBDIR=	rtems

LCLTARGET?=	i386-rtems

JAVANAME=	gcc-2.95.2
NEWLIBNAME=	newlib-1.8.2
MASTERDIR=	${.CURDIR}/../i386-rtems-gcj
PLIST=		${PKGDIR}/PLIST.${LCLTARGET}

BUILD_DEPENDS=	${LCLTARGET}-gcc:${PORTSDIR}/devel/${LCLTARGET}-gcc
RUN_DEPENDS=	${LCLTARGET}-gcc:${PORTSDIR}/devel/${LCLTARGET}-gcc

PKGNAMEPREFIX=	${LCLTARGET}-
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	all info

CONFIGURE_TARGET?=	--target=${LCLTARGET}
CONFIGURE_ARGS?=	--with-gnu-as --with-gnu-ld --with-newlib --verbose \
			--enable-languages="java"
CONFIGURE_WRKSRC?=	${WRKDIR}/build-${LCLTARGET}
CONFIGURE_SCRIPT?=	../${JAVANAME}/configure

MAKE_FLAGS=	LANGUAGES="java"

.if defined(PATCH_DEBUG)
PATCH_DEBUG_TMP=	yes
PATCH_ARGS=		-d ${WRKDIR}/${JAVANAME} -E ${PATCH_STRIP}
PATCH_DIST_ARGS=	-d ${WRKDIR} -E ${PATCH_DIST_STRIP}
.else
PATCH_DEBUG_TMP=	no
PATCH_ARGS=		-d ${WRKDIR}/${JAVANAME} --forward --quiet -E ${PATCH_STRIP}
PATCH_DIST_ARGS=	-d ${WRKDIR} --forward --quiet -E ${PATCH_DIST_STRIP}
.endif

pre-configure:
	@(cd ${WRKDIR} ; \
	cd ${JAVANAME} ; ${LN} -fs ../${NEWLIBNAME}/newlib . ; \
	cd .. ; \
	${MKDIR} build-${LCLTARGET})

do-build:
	@(cd ${WRKDIR}/build-${LCLTARGET} ; \
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

do-install:
	@(cd ${WRKDIR}/build-${LCLTARGET} && \
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

.include <bsd.port.mk>

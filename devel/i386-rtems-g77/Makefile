# New ports collection makefile for:	i386-rtems-g77
# Date created:		9 June 2000
# Whom:			James Housley <jim@thehousleys.net>
#
# $FreeBSD$
#

PORTNAME=	g77
PORTVERSION=	2.95.2
PORTREVISION=	22
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.oarcorp.com/pub/rtems/snapshots/c_tools/source/ \
		http://rtems.thehousleys.net/
DISTFILES=	${F77NAME}.tar.gz ${NEWLIBNAME}.tar.gz
PATCHFILES=	${F77NAME}-rtems-20010221.diff \
		${NEWLIBNAME}-rtems-20010221.diff
PATCH_SITES=	ftp://ftp.oarcorp.com/pub/rtems/snapshots/c_tools/source/ \
		http://rtems.thehousleys.net/

MAINTAINER=	jeh@FreeBSD.org

DIST_SUBDIR=	rtems

LCLTARGET?=	i386-rtems

F77NAME=	gcc-2.95.2
NEWLIBNAME=	newlib-1.9.0
MASTERDIR=	${.CURDIR}/../i386-rtems-g77
PLIST=		${PKGDIR}/pkg-plist.${LCLTARGET}

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

PATCH_WRKSRC=		${WRKDIR}
PATCH_STRIP=		-p

MAKE_FLAGS=	LANGUAGES="f77"

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

# New ports collection makefile for:	i386-rtems-gcc
# Date created:		9 June 2000
# Whom:			James Housley <jim@thehousleys.net>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	2.95.2
PORTREVISION=	22
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.oarcorp.com/pub/rtems/snapshots/c_tools/source/ \
		http://rtems.thehousleys.net/
DISTFILES=	${GCCNAME}.tar.gz ${NEWLIBNAME}.tar.gz
PATCHFILES=	${GCCNAME}-rtems-20010221.diff \
		${NEWLIBNAME}-rtems-20010221.diff
PATCH_SITES=	ftp://ftp.oarcorp.com/pub/rtems/snapshots/c_tools/source/ \
		http://rtems.thehousleys.net/

MAINTAINER=	jeh@FreeBSD.org

DIST_SUBDIR=	rtems

LCLTARGET?=	i386-rtems

GCCNAME=	gcc-2.95.2
NEWLIBNAME=	newlib-1.9.0
MASTERDIR=	${.CURDIR}/../i386-rtems-gcc
PLIST=		${PKGDIR}/pkg-plist.${LCLTARGET}

BUILD_DEPENDS=	autoheader:${PORTSDIR}/devel/autoconf \
		${LCLTARGET}-as:${PORTSDIR}/devel/${LCLTARGET}-binutils \
		${LCLTARGET}-ld:${PORTSDIR}/devel/${LCLTARGET}-binutils
RUN_DEPENDS=	${LCLTARGET}-as:${PORTSDIR}/devel/${LCLTARGET}-binutils \
		${LCLTARGET}-ld:${PORTSDIR}/devel/${LCLTARGET}-binutils

PKGNAMEPREFIX=	${LCLTARGET}-
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	all info

CONFIGURE_TARGET?=	--target=${LCLTARGET}
CONFIGURE_ARGS?=	--with-gnu-as --with-gnu-ld --with-newlib --verbose \
			--enable-languages=c,c++
CONFIGURE_WRKSRC?=	${WRKDIR}/build-${LCLTARGET}
CONFIGURE_SCRIPT?=	../${GCCNAME}/configure

PATCH_WRKSRC=		${WRKDIR}
PATCH_STRIP=		-p

MAKE_FLAGS=	LANGUAGES="c c++"

MAN1=		${LCLTARGET}-gcc.1 cccp.1 ${LCLTARGET}-g++.1

pre-configure:
	@(cd ${WRKDIR} ; \
	cd ${GCCNAME} ; ${LN} -fs ../${NEWLIBNAME}/newlib . ; \
	cd .. ; \
	${MKDIR} build-${LCLTARGET})

do-build:
	@(cd ${WRKDIR}/build-${LCLTARGET} ; \
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

do-install:
	@(cd ${WRKDIR}/build-${LCLTARGET} && \
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

post-install:
	@install-info ${PREFIX}/info/cpp.info ${PREFIX}/info/dir
	@install-info ${PREFIX}/info/gcc.info ${PREFIX}/info/dir

.include <bsd.port.mk>

# New ports collection makefile for:	i386-rtems-gcc
# Date created:		9 June 2000
# Whom:			James Housley <jim@thehousleys.net>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	2.95.2
CATEGORIES=	devel
MASTER_SITES=   ftp://ftp.oarcorp.com/pub/rtems/betas/rtems-4.5.0-beta/c_tools/source/ \
		http://www.thehousleys.net/rtems-4.5.0b3/
DISTFILES=	${GCCNAME}.tar.gz ${NEWLIBNAME}.tar.gz
PATCHFILES=	${GCCNAME}-rtems-20000531.diff.gz \
		${NEWLIBNAME}-rtems-20000606.diff.gz
PATCH_SITES=	ftp://ftp.oarcorp.com/pub/rtems/betas/rtems-4.5.0-beta/c_tools/source/ \
		http://www.thehousleys.net/rtems-4.5.0b3/

MAINTAINER=	jim@thehousleys.net

DIST_SUBDIR=	rtems

LCLTARGET?=	i386-rtems

GCCNAME=	gcc-2.95.2
NEWLIBNAME=	newlib-1.8.2
MASTERDIR=	${.CURDIR}/../i386-rtems-gcc
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
CONFIGURE_ARGS?=	--with-gnu-as --with-gnu-ld --with-newlib --verbose \
			--enable-languages=c,c++
CONFIGURE_WRKSRC?=	${WRKDIR}/build-${LCLTARGET}
CONFIGURE_SCRIPT?=	../${GCCNAME}/configure

MAKE_FLAGS=	LANGUAGES="c c++"

MAN1=		${LCLTARGET}-gcc.1 cccp.1 ${LCLTARGET}-g++.1

.if defined(PATCH_DEBUG)
PATCH_DIST_ARGS=   -d ${WRKDIR} -E ${PATCH_DIST_STRIP}
.else
PATCH_DIST_ARGS=   -d ${WRKDIR} --forward --quiet -E ${PATCH_DIST_STRIP}
.endif

pre-configure:
	@(cd ${WRKDIR} ; \
	cd ${GCCNAME} ; ln -fs ../${NEWLIBNAME}/newlib . ; \
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

# New ports collection makefile for:	i386-rtems-objc
# Date created:		9 June 2000
# Whom:			James Housley <jim@thehousleys.net>
#
# $FreeBSD$
#

PORTNAME=	objc
PORTVERSION=	3.2.3
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE} \
		${MASTER_SITE_GNU:S/$/:gcc/}
MASTER_SITE_SUBDIR=	newlib \
			gcc/${GCCNAME}/:gcc
DISTFILES=		${NEWLIBNAME}.tar.gz \
			${OBJCNAME}.tar.gz:gcc
PATCHFILES=	${OBJCNAME}-rtems-20030507a.diff \
		${NEWLIBNAME}-rtems-20030605.diff
PATCH_SITES=	ftp://ftp.rtems.com/pub/rtems/snapshots/c_tools/source/ \
		http://rtems.thehousleys.net/

MAINTAINER=	jeh@FreeBSD.org
COMMENT=	FSF OBJC-gcc-3.2.1 base-port for RTEMS development

.include <bsd.port.pre.mk>

LCLTARGET?=	i386-rtems

GCCVERSION=	3.2.3
OBJCNAME=	gcc-${GCCVERSION}
PLIST_SUB+=	"GCCVERSION=${GCCVERSION}"
NEWLIBNAME=	newlib-1.11.0
PLIST=		${PKGDIR}/pkg-plist.${LCLTARGET}

BUILD_DEPENDS=	${LCLTARGET}-gcc:${PORTSDIR}/devel/${LCLTARGET}-gcc
RUN_DEPENDS=	${LCLTARGET}-gcc:${PORTSDIR}/devel/${LCLTARGET}-gcc

PKGNAMEPREFIX=	${LCLTARGET}-
WANT_AUTOHEADER_VER=253
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	all info

CONFIGURE_TARGET?=	--target=${LCLTARGET}
CONFIGURE_ARGS?=	--with-gnu-as --with-gnu-ld --with-newlib --verbose \
			--enable-languages="objc" \
			--with-libiconv-prefix=${LOCALBASE} \
			--without-included-gettext
CONFIGURE_WRKSRC?=	${WRKDIR}/build-${LCLTARGET}
CONFIGURE_SCRIPT?=	../${OBJCNAME}/configure

PATCH_WRKSRC=		${WRKDIR}
PATCH_STRIP=		-p

WITHOUT_CPU_CFLAGS=	yes
MAKE_FLAGS=	LANGUAGES="objc"
MAKE_ENV=	MACHINE_ARCH=${RTEMS_ARCH} NO_CPU_CFLAGS=true

pre-configure:
	@(cd ${WRKDIR} ; \
	cd ${OBJCNAME} ; ${LN} -fs ../${NEWLIBNAME}/newlib . ; \
	cd .. ; \
	${MKDIR} build-${LCLTARGET})

do-build:
	@(cd ${WRKDIR}/build-${LCLTARGET} ; \
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

do-install:
	@(cd ${WRKDIR}/build-${LCLTARGET} && \
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

.include <bsd.port.post.mk>

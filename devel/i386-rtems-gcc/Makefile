# New ports collection makefile for:	i386-rtems-gcc
# Date created:		9 June 2000
# Whom:			James Housley <jim@thehousleys.net>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	3.2.3
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE} \
		${MASTER_SITE_SOURCEWARE:S/$/:gcc/}
MASTER_SITE_SUBDIR=	newlib \
			releases/${GCCNAME}/:gcc
DISTFILES=		${NEWLIBNAME}.tar.gz \
			${GCCNAME}.tar.gz:gcc
PATCHFILES=	${GCCNAME}-rtems-20030507a.diff \
		${NEWLIBNAME}-rtems-20030605.diff
PATCH_SITES=	ftp://ftp.rtems.com/pub/rtems/snapshots/c_tools/source/ \
		http://rtems.thehousleys.net/

MAINTAINER=	jeh@FreeBSD.org
COMMENT=	FSF C/C++-gcc-3.2.3 base-port for RTEMS development

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not build"
.endif

LCLTARGET?=	i386-rtems

GCCVERSION=	3.2.3
GCCNAME=	gcc-${GCCVERSION}
PLIST_SUB+=	"GCCVERSION=${GCCVERSION}"
NEWLIBNAME=	newlib-1.11.0
MASTERDIR=	${.CURDIR}/../i386-rtems-gcc
PLIST=		${PKGDIR}/pkg-plist.${LCLTARGET}

BUILD_DEPENDS=	autoheader:${PORTSDIR}/devel/autoconf \
		${LCLTARGET}-as:${PORTSDIR}/devel/${LCLTARGET}-binutils \
		${LCLTARGET}-ld:${PORTSDIR}/devel/${LCLTARGET}-binutils
RUN_DEPENDS=	${LCLTARGET}-as:${PORTSDIR}/devel/${LCLTARGET}-binutils \
		${LCLTARGET}-ld:${PORTSDIR}/devel/${LCLTARGET}-binutils
LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext

PKGNAMEPREFIX=	${LCLTARGET}-
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
ALL_TARGET=	all info
NO_CPUCFLAGS=	yes

CONFIGURE_TARGET?=	--target=${LCLTARGET}
CONFIGURE_ARGS?=	--with-gnu-as --with-gnu-ld --with-newlib --verbose \
			--enable-languages=c,c++ \
			--with-libiconv-prefix=${LOCALBASE} \
			--without-included-gettext
CONFIGURE_WRKSRC?=	${WRKDIR}/build-${LCLTARGET}
CONFIGURE_SCRIPT?=	../${GCCNAME}/configure

PATCH_WRKSRC=		${WRKDIR}
PATCH_STRIP=		-p

MAKE_FLAGS=	LANGUAGES="c c++"

MAN1=		${LCLTARGET}-gcc.1 ${LCLTARGET}-g++.1 \
		cpp.1 gcov.1 
MAN7=		fsf-funding.7 gfdl.7 gpl.7
INFO=		cpp cppinternals gcc gccint

pre-configure:
	@(cd ${WRKDIR} ; \
	cd ${GCCNAME} ; ${LN} -fs ../${NEWLIBNAME}/newlib . ; \
	cd .. ; \
	${MKDIR} build-${LCLTARGET})
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/gcc/configure

do-build:
	@(cd ${WRKDIR}/build-${LCLTARGET} ; \
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

do-install:
	@(cd ${WRKDIR}/build-${LCLTARGET} && \
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

post-install:
	@install-info ${PREFIX}/info/cpp.info ${PREFIX}/info/dir
	@install-info ${PREFIX}/info/gcc.info ${PREFIX}/info/dir

.include <bsd.port.post.mk>

# New ports collection makefile for:	D Front End for GCC
# Date created:		18 November 2004
# Whom:			Masanori OZAWA (ozawa@ongs.co.jp)
#
# $FreeBSD$
#

PORTNAME=	gdc
PORTVERSION=	0.19
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GCC} \
		${MASTER_SITE_SOURCEFORGE:S/%SUBDIR%/dgcc/g:S/$/:gdc/g}
MASTER_SITE_SUBDIR=	${GCC_MASTER_SITE_SUBDIR}
DISTFILES=	${DISTNAME}-src${EXTRACT_SUFX}:gdc \
		gcc-core-${GCC_VERSIONSTRING}${EXTRACT_SUFX} \
		gcc-g++-${GCC_VERSIONSTRING}${EXTRACT_SUFX}

MAINTAINER=	ozawa@ongs.co.jp
COMMENT=	D Front End for GCC

ONLY_FOR_ARCHS=	i386

USE_BISON=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes

SRCDIR=		${WRKDIR}/gcc-${GCC_VERSIONSTRING}
WRKSRC=		${WRKDIR}/build
PATCH_WRKSRC=	${SRCDIR}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-nls \
		--with-system-zlib \
		--with-libiconv-prefix=${LOCALBASE} \
		--disable-shared \
		--enable-languages=c,c++,d
CONFIGURE_SCRIPT=	../${SRCDIR:C/${WRKDIR}\///}/configure

PLIST_SUB=	GCC_VER=${GCC_VERSION} CONF_TARGET=${CONFIGURE_TARGET}

MAN1=		gdc.1

.ifndef TARGET_GCC
TARGET_GCC=	3.4	# default
.elif ${TARGET_GCC} != 3.4 && ${TARGET_GCC} != 4.0
.error it cannot be specified as TARGET_GCC other than 3.4 or 4.0
.endif

.if ${TARGET_GCC} == 4.0
GCC_VERSION=	4.0.4
GCC_REVISION=	20060720
GCC_VERSIONSTRING=	4.0-${GCC_REVISION}
GCC_MASTER_SITE_SUBDIR=	snapshots/${GCC_VERSIONSTRING}
.else
GCC_VERSION=	3.4.6
GCC_VERSIONSTRING=	${GCC_VERSION}
GCC_MASTER_SITE_SUBDIR=	releases/gcc-${GCC_VERSIONSTRING}
.endif

GCCDIR=		${SRCDIR}/gcc
GDC_INC=	${PREFIX}/include/d/${GCC_VERSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500039
# GDC required g++ version on the system of 3.x 4.0.1 and later.
IGNORE=		it is supported on FreeBSD 5.x and later
.endif

.if ${ARCH} == "amd64"
# I hope the GDC will support amd64.
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.endif

pre-fetch:
	@${ECHO_CMD}
	@${ECHO_CMD} "======================================================="
	@${ECHO_CMD}
	@${ECHO_CMD} "GDC is built with GCC version '${TARGET_GCC}'."
	@${ECHO_CMD}
	@${ECHO_CMD} "You can set 'TARGET_GCC' variable to '3.4' or '4.0'."
	@${ECHO_CMD}
	@${ECHO_CMD} "======================================================="
	@${ECHO_CMD}

post-extract:
	@${MV} ${WRKDIR}/d ${GCCDIR}

post-patch:
	@(cd ${SRCDIR} && ${SH} ./gcc/d/setup-gcc.sh)
	@${REINPLACE_CMD} -e \
		's|\(const char version_string.*\)";|\1 [FreeBSD]";|' \
		${GCCDIR}/version.c
	@${REINPLACE_CMD} -e \
		's|^\(gcc_d_include_dir\).*|\1 = ${GDC_INC}|' \
		${GCCDIR}/d/Make-lang.in

pre-configure:
	@(cd ${SRCDIR} && contrib/gcc_update --touch)
	@${RM} -f ${SRCDIR}/gcc/*/*.info*
	@${MKDIR} ${CONFIGURE_WRKSRC}

post-build:
	@${ECHO_CMD}
	@${ECHO_CMD} "======================================================="
	@${ECHO_CMD}
	@${ECHO_CMD} "To test the Phobos run-time library run 'make check'."
	@${ECHO_CMD}
	@${ECHO_CMD} "Note that some tests will fail."
	@${ECHO_CMD}
	@${ECHO_CMD} "======================================================="
	@${ECHO_CMD}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gcc/gdc ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/gcc/cc1d ${PREFIX}/bin
	${INSTALL_MAN} ${GCCDIR}/d/gdc.1 ${PREFIX}/man/man1
	@(cd ${WRKSRC} && ${GMAKE} install-target-libphobos)

check: build
	@(cd ${WRKSRC} && ${GMAKE} check-target-libphobos)

.include <bsd.port.post.mk>

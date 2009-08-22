# New ports collection makefile for:	D Front End for GCC
# Date created:		18 November 2004
# Whom:			Masanori OZAWA (ozawa@ongs.co.jp)
#
# $FreeBSD$
#

PORTNAME=	gdc
PORTVERSION=	0.24
PORTREVISION=	6
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GCC} \
		SF/dgcc/${PORTNAME}/${PORTVERSION}:gdc
MASTER_SITE_SUBDIR=	${GCC_MASTER_SITE_SUBDIR}
DISTFILES=	${DISTNAME}-src${EXTRACT_SUFX}:gdc \
		gcc-core-${GCC_VERSIONSTRING}${EXTRACT_SUFX} \
		gcc-g++-${GCC_VERSIONSTRING}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	D Front End for GCC

ONLY_FOR_ARCHS=	i386 amd64

USE_BISON=	build
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_ICONV=	yes

SRCDIR=		${WRKDIR}/gcc-${GCC_VERSIONSTRING}
WRKSRC=		${WRKDIR}/build
PATCH_WRKSRC=	${SRCDIR}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-nls \
		--with-system-zlib \
		--with-libiconv-prefix=${LOCALBASE} \
		--disable-shared \
		--enable-languages=c,c++,d \
		--enable-thread-lib=-pthread
CONFIGURE_SCRIPT=	../${SRCDIR:C/${WRKDIR}\///}/configure

PLIST_SUB=	GCC_VER=${GCC_VERSION} CONF_TARGET=${CONFIGURE_TARGET}

MAN1=		gdc.1 gdmd.1

GCCDIR=		${SRCDIR}/gcc
GDC_INC=	${PREFIX}/include/d/${GCC_VERSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800041
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-gcc-d-phobos-std-math.d
.endif

.ifndef TARGET_GCC
.if ${OSVERSION} >= 700000 || ${ARCH} == "amd64"
TARGET_GCC=	4.1
.else
TARGET_GCC=	3.4
.endif
.elif ${TARGET_GCC} != 3.4 && ${TARGET_GCC} != 4.0 && ${TARGET_GCC} != 4.1
.error it cannot be specified as TARGET_GCC other than 3.4, 4.0 or 4.1
.endif

.if ${TARGET_GCC} == 4.1
GCC_VERSION=	4.1.3
GCC_REVISION=	20080428
GCC_VERSIONSTRING=	4.1-${GCC_REVISION}
GCC_MASTER_SITE_SUBDIR=	snapshots/${GCC_VERSIONSTRING}
.elif ${TARGET_GCC} == 4.0
GCC_VERSION=	4.0.4
GCC_VERSIONSTRING=	${GCC_VERSION}
GCC_MASTER_SITE_SUBDIR=	releases/gcc-${GCC_VERSIONSTRING}
.else
GCC_VERSION=	3.4.6
GCC_VERSIONSTRING=	${GCC_VERSION}
GCC_MASTER_SITE_SUBDIR=	releases/gcc-${GCC_VERSIONSTRING}
.endif

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.endif

pre-fetch:
	@${ECHO_CMD}
	@${ECHO_CMD} "========================================================="
	@${ECHO_CMD}
	@${ECHO_CMD} "GDC is built with GCC version '${TARGET_GCC}'."
	@${ECHO_CMD}
	@${ECHO_CMD} "You can set one of the following variables as TARGET_GCC."
	@${ECHO_CMD}
	@${ECHO_CMD} " '3.4' , '4.0' , '4.1'"
	@${ECHO_CMD}
	@${ECHO_CMD} "========================================================="
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
	@${REINPLACE_CMD} -e 's, BsdSockets_salen, GNU_BsdSockets_salen,' \
		${GCCDIR}/d/phobos/config/unix-mid

pre-configure:
	@(cd ${SRCDIR} && contrib/gcc_update --touch)
	@${RM} -f ${SRCDIR}/gcc/*/*.info*
	@${MKDIR} ${CONFIGURE_WRKSRC}

post-build:
	@${ECHO_CMD}
	@${ECHO_CMD} "========================================================="
	@${ECHO_CMD}
	@${ECHO_CMD} "To test the Phobos run-time library run 'make check'."
	@${ECHO_CMD}
	@${ECHO_CMD} "Note that some tests will fail."
	@${ECHO_CMD}
	@${ECHO_CMD} "========================================================="
	@${ECHO_CMD}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gcc/gdc ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/gcc/cc1d ${PREFIX}/bin
	${INSTALL_SCRIPT} ${GCCDIR}/d/dmd-script ${PREFIX}/bin/gdmd
.ifndef NOPORTDOCS
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${GCCDIR}/d/GDC.html ${DOCSDIR}
	${INSTALL_DATA} ${GCCDIR}/d/README ${DOCSDIR}/README.gdc
.endif
	${INSTALL_MAN} ${GCCDIR}/d/gdc.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${GCCDIR}/d/dmd-script.1 ${PREFIX}/man/man1/gdmd.1
	@(cd ${WRKSRC} && ${GMAKE} install-target-libphobos)

check: build
	@(cd ${WRKSRC} && ${GMAKE} check-target-libphobos)

.include <bsd.port.post.mk>

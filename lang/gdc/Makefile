# New ports collection makefile for:	D Front End for GCC
# Date created:		18 November 2004
# Whom:			Masanori OZAWA (ozawa@ongs.co.jp)
#
# $FreeBSD$
#

PORTNAME=	gdc
PORTVERSION=	0.16
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GCC} \
		http://home.earthlink.net/~dvdfrdmn/d/:gdc
MASTER_SITE_SUBDIR=	snapshots/${GCC_VERSIONSTRING}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:gdc \
		gcc-core-${GCC_VERSIONSTRING}${EXTRACT_SUFX} \
		gcc-g++-${GCC_VERSIONSTRING}${EXTRACT_SUFX}

MAINTAINER=	ozawa@ongs.co.jp
COMMENT=	D Front End for GCC

ONLY_FOR_ARCHS=	i386

USE_BISON=	yes
USE_BZIP2=	yes
USE_GCC=	3.4
USE_GMAKE=	yes
USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/gcc-${GCC_VERSIONSTRING}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-nls \
		--with-system-zlib \
		--with-libiconv-prefix=${LOCALBASE} \
		--disable-shared \
		--enable-languages=c,c++,d

PLIST_SUB=	GCC_VER=${GCC_VERSION} CONF_TARGET=${CONFIGURE_TARGET}

MAN1=		gdc.1

GCCDIR=		${WRKSRC}/gcc
GCC_VERSION=	3.4.5
GCC_REVISION=	20050920
GCC_VERSIONSTRING=	3.4-${GCC_REVISION}
GDC_INC=	${PREFIX}/include/d/${GCC_VERSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		It is supported on FreeBSD 5.x and later.
.endif

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.endif

post-extract:
	@${MV} ${WRKDIR}/d ${GCCDIR}

post-patch:
	@(cd ${WRKSRC} && ${SH} ./gcc/d/setup-gcc.sh)
	@${REINPLACE_CMD} -e \
		's|\(const char version_string.*\)";|\1 [FreeBSD]";|' \
		${GCCDIR}/version.c
	@${REINPLACE_CMD} -e \
		's|^\(gcc_d_include_dir\).*|\1 = ${GDC_INC}|' \
		${GCCDIR}/d/Make-lang.in

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
	${INSTALL_PROGRAM} ${GCCDIR}/gdc ${PREFIX}/bin
	${INSTALL_PROGRAM} ${GCCDIR}/cc1d ${PREFIX}/bin
	${INSTALL_MAN} ${GCCDIR}/d/gdc.1 ${PREFIX}/man/man1
	@(cd ${WRKSRC} && ${GMAKE} install-target-libphobos)

check: build
	@(cd ${WRKSRC} && ${GMAKE} check-target-libphobos)

.include <bsd.port.post.mk>

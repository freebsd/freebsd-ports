# New ports collection makefile for:	D Front End for GCC
# Date created:		18 November 2004
# Whom:			Masanori OZAWA (ozawa@ongs.co.jp)
#
# $FreeBSD$
#

PORTNAME=	gdc
PORTVERSION=	0.10
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GCC} \
		http://home.earthlink.net/~dvdfrdmn/d/:gdc \
		http://www.hpl.hp.com/personal/Hans_Boehm/gc/gc_source/:boehm
MASTER_SITE_SUBDIR=	snapshots/${GCC_VERSIONSTRING}
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.bz2:gdc \
		gcc-core-${GCC_VERSIONSTRING}.tar.bz2 \
		gcc-g++-${GCC_VERSIONSTRING}.tar.bz2 \
		${BOEHM_SRC_PKG}:boehm
EXTRACT_ONLY=	gcc-core-${GCC_VERSIONSTRING}.tar.bz2 \
		gcc-g++-${GCC_VERSIONSTRING}.tar.bz2

MAINTAINER=	daichi@FreeBSD.org
COMMENT=	D Front End for GCC

BUILD_DEPENDS=	gcc34:${PORTSDIR}/lang/gcc34 \
		bison:${PORTSDIR}/devel/bison
RUN_DEPENDS=	gcc34:${PORTSDIR}/lang/gcc34

ONLY_FOR_ARCHS=	i386 amd64 alpha

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_REINPLACE=	yes

GCC_VERSION=	3.4.4
GCC_REVISION=	20050107
GCC_VERSIONSTRING=	3.4-${GCC_REVISION}

BOEHM_VERSION=	6.4
BOEHM_SRC_PKG=	gc${BOEHM_VERSION}.tar.gz
BOEHM_PATCH=	boehm-gc.20050102.patch

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		"It is supported on FreeBSD 5.x and later"
.endif

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
.endif

GXX_INC=${PREFIX}/lib/gcc/${CONFIGURE_TARGET}/${GCC_VERSION}/include/c++/
SUFFIX=	34
CONFIGURE_ARGS+=--disable-nls --with-system-zlib \
		--with-libiconv-prefix=${LOCALBASE} \
		--program-suffix=${SUFFIX} \
		--with-gxx-include-dir=${GXX_INC} \
		--disable-shared --prefix=${PREFIX} \
		--enable-languages=c,d,c++
MAKE_ARGS+=     MAKEINFOFLAGS="--no-split"
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/gcc-${GCC_VERSIONSTRING}
GCCDIR=		${WRKSRC}/gcc
D_DIR=		${GCCDIR}/d
PHOBOSDIR=	${D_DIR}/phobos

CC=		${PREFIX}/bin/gcc34
CXX=		${PREFIX}/bin/g++34
DMD=		gdc
DFLAGS=		-O2 -frelease
PHOBOS_BUILD_ARGS=	CC=${CC} CXX=${CXX} DMD=${DMD} DFLAGS="${DFLAGS}" \
			PATH="${PATH}:${GCCDIR}"

post-extract:
	@${TAR} xjf ${DISTDIR}/${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		-C ${GCCDIR}
	@${RM} ${PHOBOSDIR}/boehm-gc
	@${TAR} xzf ${DISTDIR}/${BOEHM_SRC_PKG} -C ${PHOBOSDIR}
	@${MV} ${PHOBOSDIR}/gc${BOEHM_VERSION} ${PHOBOSDIR}/boehm-gc

post-patch:
	@cd ${GCCDIR} && ${PATCH} -p1 < d/patch-gcc-3.4.x
	@echo "++ Patching for d/phobos/boehm-gc ++"
	@cd ${PHOBOSDIR}/boehm-gc && ${PATCH} < ${PATCHDIR}/${BOEHM_PATCH}
	@${REINPLACE_CMD} -e \
		's|\(const char version_string.*\)";|\1 [FreeBSD]";|' \
		${WRKSRC}/gcc/version.c

post-build:
	@${MKDIR} ${WRKSRC}/phobos_build
	@cd ${WRKSRC}/phobos_build && ${PHOBOS_BUILD_ARGS} \
		../gcc/d/phobos/configure --prefix=${PREFIX}
	@cd ${WRKSRC}/phobos_build && \
		${PHOBOS_BUILD_ARGS} ${GMAKE}
	@cd ${WRKSRC}/phobos_build && \
		${PHOBOS_BUILD_ARGS} ${GMAKE} unittest

do-install:
	${INSTALL} -o root -g wheel -m 755 ${GCCDIR}/gdc ${PREFIX}/bin/
	@${STRIP_CMD} ${PREFIX}/bin/gdc
	${INSTALL} -o root -g wheel -m 755 ${GCCDIR}/cc1d ${PREFIX}/bin/
	@${STRIP_CMD} ${PREFIX}/bin/cc1d
	@cd ${WRKSRC}/phobos_build && ${GMAKE} install

.include <bsd.port.post.mk>

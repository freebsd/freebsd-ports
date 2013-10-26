# Created by: Tassilo Philipp <tphilipp@potion-studios.com>
# $FreeBSD$

PORTNAME=		gcc
PORTVERSION=		4.6.2
PORTREVISION=	1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GCC}
MASTER_SITE_SUBDIR=	releases/${DISTNAME}/
PKGNAMEPREFIX=		psptoolchain-
PKGNAMESUFFIX?=		-stage1

MAINTAINER=		tphilipp@potion-studios.com
COMMENT=		PlayStation Portable development toolchain ${PORTNAME}

ONLY_FOR_ARCHS=		amd64 i386

PSP_GCC_STAGE_PREFIX=	psp/stage1

LIB_DEPENDS=		libgmp.so:${PORTSDIR}/math/gmp \
			libmpfr.so:${PORTSDIR}/math/mpfr \
			libmpc.so:${PORTSDIR}/math/mpc

BUILD_DEPENDS+=		psp-addr2line:${PORTSDIR}/devel/psptoolchain-binutils \
			psp-ar:${PORTSDIR}/devel/psptoolchain-binutils \
			psp-as:${PORTSDIR}/devel/psptoolchain-binutils \
			psp-c++filt:${PORTSDIR}/devel/psptoolchain-binutils \
			psp-ld:${PORTSDIR}/devel/psptoolchain-binutils \
			psp-nm:${PORTSDIR}/devel/psptoolchain-binutils \
			psp-objcopy:${PORTSDIR}/devel/psptoolchain-binutils \
			psp-objdump:${PORTSDIR}/devel/psptoolchain-binutils \
			psp-ranlib:${PORTSDIR}/devel/psptoolchain-binutils \
			psp-readelf:${PORTSDIR}/devel/psptoolchain-binutils \
			psp-size:${PORTSDIR}/devel/psptoolchain-binutils \
			psp-strings:${PORTSDIR}/devel/psptoolchain-binutils \
			psp-strip:${PORTSDIR}/devel/psptoolchain-binutils

USE_BZIP2=		yes
USE_GMAKE=		yes

PATCH_WRKSRC=		${SRCDIR}
CONFIGURE_SCRIPT=	../${SRCDIR:S/${WRKDIR}\///}/configure

SRCDIR=			${WRKDIR}/${PORTNAME}-${PORTVERSION}
WRKSRC=			${WRKDIR}/build

MAKE_ENV+=		PATH=${LOCALBASE}/${PSP_GCC_STAGE_PREFIX}/bin:${PREFIX}/bin:${PATH}
HAS_CONFIGURE=		yes
CONFIGURE_ARGS?=	--prefix=${PREFIX}/${PSP_GCC_STAGE_PREFIX} \
			--target="psp" \
			--enable-languages="c" \
			--enable-lto \
			--with-newlib \
			--with-gmp=${LOCALBASE} \
			--with-mpfr \
			--without-headers \
			--disable-libssp \
			--disable-nls \
			--with-ld=${LOCALBASE}/bin/psp-ld \
			--with-as=${LOCALBASE}/bin/psp-as \
			--mandir=${PREFIX}/man

NO_STAGE=	yes
pre-configure:
	@${MKDIR} ${CONFIGURE_WRKSRC}

# Don't install any documentation for psptoolchain's gcc stage 1 - makes no sense.
# Disable installation of .info files and libiberty for both stages.
post-patch:
	@${REINPLACE_CMD} -E "s/^(install-data-am:)(.*)install-info-am(.*)/\1 \2 \3/" \
		${SRCDIR}/libquadmath/Makefile.in
	@${REINPLACE_CMD} -E "s/^(install:)(.*)/\1#\2/" ${SRCDIR}/libiberty/Makefile.in
	@${REINPLACE_CMD} -E \
		-e "/^	\\$$\(mkinstalldirs\) \\$$\(DESTDIR\)\\$$\((infodir|man7dir)\)/d" \
		-e "s/^(install-info:)(.*)/\1#\2/" \
		-e "/^	\\$$\(DESTDIR\)\\$$\(man7dir\)\/(fsf-funding|gfdl|gpl)\\$$\(man7ext\)/d" \
		${SRCDIR}/gcc/Makefile.in
.if ${PKGNAMESUFFIX} == "-stage1"
	@${REINPLACE_CMD} -E "s/^(install-man:)(.*)/\1#\2/" ${SRCDIR}/gcc/Makefile.in
.endif

# Stage 2 installs (1) man pages.
.if ${PKGNAMESUFFIX} != "-stage1"

MAN1+=			psp-cpp.1 \
			psp-gcc.1 \
			psp-gcov.1

.endif

PLIST_SUB+=		PSP_GCC_STAGE_PREFIX=${PSP_GCC_STAGE_PREFIX}

.include <bsd.port.mk>

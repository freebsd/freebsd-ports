# Created by: Tassilo Philipp <tphilipp@potion-studios.com>
# $FreeBSD$

PORTNAME=		gcc
PORTVERSION=		4.6.2
PORTREVISION?=		3
CATEGORIES=		devel
MASTER_SITES=		GCC/releases/${DISTNAME}
PKGNAMEPREFIX=		psptoolchain-
PKGNAMESUFFIX?=		-stage1

MAINTAINER=		tphilipp@potion-studios.com
COMMENT=		PlayStation Portable development toolchain ${PORTNAME}

ONLY_FOR_ARCHS=		amd64 i386

PSP_GCC_STAGE_PREFIX=	psp/stage1

LIB_DEPENDS=		libgmp.so:math/gmp \
			libmpfr.so:math/mpfr \
			libmpc.so:math/mpc

BUILD_DEPENDS+=		psp-addr2line:devel/psptoolchain-binutils \
			psp-ar:devel/psptoolchain-binutils \
			psp-as:devel/psptoolchain-binutils \
			psp-c++filt:devel/psptoolchain-binutils \
			psp-ld:devel/psptoolchain-binutils \
			psp-nm:devel/psptoolchain-binutils \
			psp-objcopy:devel/psptoolchain-binutils \
			psp-objdump:devel/psptoolchain-binutils \
			psp-ranlib:devel/psptoolchain-binutils \
			psp-readelf:devel/psptoolchain-binutils \
			psp-size:devel/psptoolchain-binutils \
			psp-strings:devel/psptoolchain-binutils \
			psp-strip:devel/psptoolchain-binutils

USES=			gmake libtool tar:bzip2

MAKE_ENV+=		PATH=${LOCALBASE}/${PSP_GCC_STAGE_PREFIX}/bin:${PREFIX}/bin:${PATH}
HAS_CONFIGURE=		yes
CONFIGURE_OUTSOURCE=	yes
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

# Don't install any documentation for psptoolchain's gcc stage 1 - makes no sense.
# Disable installation of .info files and libiberty for both stages.
post-patch:
	@${REINPLACE_CMD} -E "s/^(install-data-am:)(.*)install-info-am(.*)/\1 \2 \3/" \
		${PATCH_WRKSRC}/libquadmath/Makefile.in
	@${REINPLACE_CMD} -E "s/^(install:)(.*)/\1#\2/" ${PATCH_WRKSRC}/libiberty/Makefile.in
	@${REINPLACE_CMD} -E \
		-e "/^	\\$$\(mkinstalldirs\) \\$$\(DESTDIR\)\\$$\((infodir|man7dir)\)/d" \
		-e "s/^(install-info:)(.*)/\1#\2/" \
		-e "/^	\\$$\(DESTDIR\)\\$$\(man7dir\)\/(fsf-funding|gfdl|gpl)\\$$\(man7ext\)/d" \
		${PATCH_WRKSRC}/gcc/Makefile.in
.if ${PKGNAMESUFFIX} == "-stage1"
	@${REINPLACE_CMD} -E "s/^(install-man:)(.*)/\1#\2/" ${PATCH_WRKSRC}/gcc/Makefile.in
.endif

PLIST_SUB+=		PSP_GCC_STAGE_PREFIX=${PSP_GCC_STAGE_PREFIX}

.include <bsd.port.mk>

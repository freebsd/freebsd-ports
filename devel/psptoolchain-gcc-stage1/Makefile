# New ports collection makefile for: psptoolchain-gcc-stage1
# Date created:        19 July 2009
# Whom:                Tassilo Philipp <tphilipp@potion-studios.com>
#
# $FreeBSD$
#

PORTNAME=		gcc
PORTVERSION=		4.1.0
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GCC}
MASTER_SITE_SUBDIR=	releases/${DISTNAME}/
PKGNAMEPREFIX=		psptoolchain-
PKGNAMESUFFIX?=		-stage1

MAINTAINER=		tphilipp@potion-studios.com
COMMENT=		PlayStation Portable development toolchain ${PORTNAME}

PSP_GCC_STAGE_PREFIX=	psp/stage1

BUILD_DEPENDS+=		psp-addr2line:${PORTSDIR}/devel/psptoolchain-binutils \
			psp-ar:${PORTSDIR}/devel/psptoolchain-binutils \
			psp-as:${PORTSDIR}/devel/psptoolchain-binutils \
			psp-c++filt:${PORTSDIR}/devel/psptoolchain-binutils \
			psp-gprof:${PORTSDIR}/devel/psptoolchain-binutils \
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

HAS_CONFIGURE=		yes
MAKE_ENV+=		PATH=${PREFIX}/${PSP_GCC_STAGE_PREFIX}/bin:${PATH}
CONFIGURE_ARGS?=	--prefix=${PREFIX}/${PSP_GCC_STAGE_PREFIX} --target="psp" --enable-languages="c" --with-newlib --without-headers --disable-libssp --disable-nls --with-as=`which psp-as` --with-ld=`which psp-ld`

# Don't install documentation for psptoolchain's gcc stage 1 - makes no sense.
.if ${PKGNAMESUFFIX} == "-stage1"

post-patch:
	@${REINPLACE_CMD} -E 's/^(install-info:)(.*)/\1#\2/' ${WRKSRC}/gcc/Makefile.in
	@${REINPLACE_CMD} -E 's/^(install-man:)(.*)/\1#\2/' ${WRKSRC}/gcc/Makefile.in
	@${REINPLACE_CMD} -E 's/^(install:)(.*)/\1#\2/' ${WRKSRC}/libiberty/Makefile.in

.else

# Disable installation of .info files and libiberty.
post-patch:
	@${REINPLACE_CMD} -E 's/^(install-info:)(.*)/\1#\2/' ${WRKSRC}/gcc/Makefile.in
	@${REINPLACE_CMD} -E 's/^(install:)(.*)/\1#\2/' ${WRKSRC}/libiberty/Makefile.in

MAN1+=			psp-cpp.1 \
			psp-gcc.1 \
			psp-gcov.1
MAN7=			fsf-funding.7 \
			gfdl.7 \
			gpl.7

.endif

PLIST_SUB+=		PSP_GCC_STAGE_PREFIX=${PSP_GCC_STAGE_PREFIX}

.include <bsd.port.mk>

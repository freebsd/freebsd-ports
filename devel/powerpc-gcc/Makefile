# New ports collection makefile for:	powerpc-gcc
# Date created:		9 Marth 2006
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	4.1.1
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GCC}
MASTER_SITE_SUBDIR=	releases/${DISTNAME}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	GNU gcc 4.1.1 for PowerPC/RS6000 cross-development

WRKSRC=		${WRKDIR}/gcc-${PORTVERSION}

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_BISON=	build
GNU_CONFIGURE=	yes
STRIP=
NO_MTREE=yes

DEPRECIATED=	deprecated; use cross-gcc instead
EXPIRE_DATE=	2009-04-19

.if defined(WITH_ABI)
OUR_ABI=	${WITH_ABI}
.else
OUR_ABI=	eabi
.endif

OUR_TARGET=	powerpc-elf-${OUR_ABI}

PKGNAMEPREFIX=	${OUR_TARGET}-
PREFIX?=	${LOCALBASE}/${OUR_TARGET}

BUILD_DEPENDS=	${PREFIX}/bin/${PKGNAMEPREFIX}as:${PORTSDIR}/devel/powerpc-binutils \
		${PREFIX}/bin/${PKGNAMEPREFIX}ld:${PORTSDIR}/devel/powerpc-binutils
RUN_DEPENDS=	${PREFIX}/bin/${PKGNAMEPREFIX}as:${PORTSDIR}/devel/powerpc-binutils \
		${PREFIX}/bin/${PKGNAMEPREFIX}ld:${PORTSDIR}/devel/powerpc-binutils

#override user-defined settings in make.conf
WITHOUT_CPU_CFLAGS=	yes

MAKE_FLAGS=	LANGUAGES="c c++ objc"
MAKE_ENV=	MACHINE_ARCH=powerpc \
		NO_CPU_CFLAGS=true \
		PATH=${PREFIX}/bin:${PATH}

CONFIGURE_ENV=	PATH=${PREFIX}/bin:${PATH}

PLIST_SUB+=	TOOLPREFIX=${OUR_TARGET} \
		GCC_VER=${PORTVERSION}

OUR_LIBDIR=	${PREFIX}/lib/gcc/${OUR_TARGET}

CONFIGURE_ARGS=	--target=${OUR_TARGET} \
		--enable-languages=c,c++,objc \
		--with-dwarf2 \
		--with-system-zlib \
		--disable-nls \
		--with-libiconv-prefix=${LOCALDIR} \
		--libdir=${OUR_LIBDIR} \
		--with-gxx-include-dir=${OUR_LIBDIR}/include/cxx/ \
		--disable-multilib \
		--with-newlib \
		--disable-shared

MAN1=		${OUR_TARGET}-cpp.1 \
		${OUR_TARGET}-g++.1 \
		${OUR_TARGET}-gcc.1 \
		${OUR_TARGET}-gcov.1 \

MAN7=		fsf-funding.7 gfdl.7 gpl.7
INFO=		cpp cppinternals gcc gccinstall gccint

LN_BINARIES=	addr2line ar as c++filt ld \
		nm objcopy objdump ranlib \
		readelf size strings strip

.include <bsd.port.pre.mk>

.if defined(WITH_CPU)
CONFIGURE_ARGS+=--with-cpu=${WITH_CPU} \
		--enable-cxx-flags=${WITH_CPU}
.endif

.if defined(WITH_FLOAT_TYPE)
CONFIGURE_ARGS+=--with-float=${WITH_FLOAT_TYPE}
.endif

pre-everything::
	@${ECHO_MSG} "---------------------------------------------------------"
	@${ECHO_MSG} "You can specify default CPU target using WITH_CPU option"
	@${ECHO_MSG} "Target FPU type can be provided through WITH_FLOAT_TYPE"
	@${ECHO_MSG} "---------------------------------------------------------"

post-install:
.for F in ${LN_BINARIES}   
	@${LN} -sf ../../../../bin/${PKGNAMEPREFIX}$F \
		${PREFIX}/libexec/gcc/${OUR_TARGET}/${PORTVERSION}/$F
.endfor

.include <bsd.port.post.mk>

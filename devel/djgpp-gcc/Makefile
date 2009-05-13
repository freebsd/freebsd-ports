# New ports collection makefile for:	djgpp-gcc
# Date created:		27 Jan 2007
# Whom:			Peter Johnson <johnson.peter@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	${GCCVERSION}
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.delorie.com/pub/djgpp/current/v2gnu/:djsource \
		ftp://ftp.mirror.ac.uk/sites/www.delorie.com/current/v2gnu/:djsource \
		http://djgpp.linux-mirror.org/v2gnu/:djsource \
		http://djgpp.oss-mirror.org/v2gnu/:djsource \
		${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	${PORTNAME}/releases/${PORTNAME}-${GCCVERSION}
PKGNAMEPREFIX=	djgpp-
DISTFILES=	gcc410s2.zip:djsource \
		${PORTNAME}-core-${GCCVERSION}.tar.gz \
		${PORTNAME}-g++-${GCCVERSION}.tar.gz \
		${PORTNAME}-objc-${GCCVERSION}.tar.gz \
#		${PORTNAME}-ada-${GCCVERSION}.tar.gz
EXTRACT_ONLY=	gcc410s2.zip

MAINTAINER=	johnson.peter@gmail.com
COMMENT=	FSF gcc-4.1 for DJGPP cross-development

BUILD_DEPENDS=	${TARGET}-as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils \
		${LOCALBASE}/${TARGET}/bin/stubify:${PORTSDIR}/devel/${PKGNAMEPREFIX}crx \
		autoconf-2.13:${PORTSDIR}/devel/autoconf213 \
		autoconf-2.62:${PORTSDIR}/devel/autoconf262 \
		aclocal-1.9:${PORTSDIR}/devel/automake19
.if defined(WITH_FORTRAN)
LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4 \
		mpfr.3:${PORTSDIR}/math/mpfr
.endif
RUN_DEPENDS=	${TARGET}-as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils \
		${LOCALBASE}/${TARGET}/bin/stubify:${PORTSDIR}/devel/${PKGNAMEPREFIX}crx

TARGET=		i586-pc-msdosdjgpp
GCCVERSION=	4.1.0

USE_ZIP=	yes
USE_PERL5_BUILD=yes
USE_GMAKE=	yes
USE_ICONV=	yes
SCRIPTS_ENV=	gcc_dir=${SRCDIR} PATCH=${PATCH}

PATCH_WRKSRC=	${SRCDIR}
CONFIGURE_SCRIPT=	../${SRCDIR:C/${WRKDIR}//}/configure

SRCDIR=		${WRKDIR}/gnu/gcc-${GCCVERSION}
WRKSRC=		${WRKDIR}/build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=${TARGET} \
		--with-gcc --with-gnu-ld --with-gnu-as \
		--disable-nls --disable-shared \
		--with-gxx-include-dir=${PREFIX}/${TARGET}/include/c++/ \
		--includedir=${PREFIX}/${TARGET}/include \
		--datadir=${PREFIX}/${TARGET}/share
.if defined(WITH_FORTRAN)
CONFIGURE_ARGS+=--enable-languages=c,c++,fortran,objc,obj-c++
.else
CONFIGURE_ARGS+=--enable-languages=c,c++,objc,obj-c++
.endif
INFO_PATH=	${TARGET}/info

MAKE_ENV=	PATH=${PREFIX}/bin:${PATH}
LIBTOOLFILES=	configure gcc/configure
MAN1=		${TARGET}-gcc.1 ${TARGET}-g++.1 \
		${TARGET}-cpp.1 ${TARGET}-gcov.1

PLIST_SUB+=	GCC_TARG=${TARGET} GCC_REV=${GCCVERSION}

INFO=		cpp cppinternals gcc gccinstall gccint
INFO_PATH=	${TARGET}/info

BINARIES=	gcc cpp g++ gcov

.include <bsd.port.pre.mk>

.if defined(WITH_FORTRAN)
DISTFILES+=	${PORTNAME}-fortran-${GCCVERSION}.tar.gz
CONFIGURE_ARGS+=--with-gmp=${LOCALBASE}
MAN1+=		${TARGET}-gfortran.1
INFO+=		gfortran
BINARIES+=	gfortran
PLIST_SUB+=	FORTRAN=""
.else
PLIST_SUB+=	FORTRAN="@comment "
.endif

.if exists(${LOCALBASE}/lib/libiconv.so.3)
WITH_LIBICONV=	yes
.endif

.if defined(WITH_LIBICONV)
USE_ICONV=	yes
CONFIGURE_ARGS+=	--with-libiconv-prefix=${LOCALBASE}
.endif

post-extract:
	@${MKDIR} ${WRKDIR}/gnu
	@cd ${WRKDIR}/gnu && ${GZIP_CMD} -dc ${DISTDIR}/${PORTNAME}-core-${GCCVERSION}.tar.gz | ${TAR} -xf -
	@cd ${WRKDIR}/gnu && ${GZIP_CMD} -dc ${DISTDIR}/${PORTNAME}-g++-${GCCVERSION}.tar.gz | ${TAR} -xf -
.if defined(WITH_FORTRAN)
	@cd ${WRKDIR}/gnu && ${GZIP_CMD} -dc ${DISTDIR}/${PORTNAME}-fortran-${GCCVERSION}.tar.gz | ${TAR} -xf -
.endif
	@cd ${WRKDIR}/gnu && ${GZIP_CMD} -dc ${DISTDIR}/${PORTNAME}-objc-${GCCVERSION}.tar.gz | ${TAR} -xf -
#	@cd ${WRKDIR}/gnu && ${GZIP_CMD} -dc ${DISTDIR}/${PORTNAME}-ada-${GCCVERSION}.tar.gz | ${TAR} -xf -
	@${RM} -rf ${SRCDIR}/boehm-gc
	@${RM} -rf ${SRCDIR}/fastjar
	@${RM} -rf ${SRCDIR}/libffi
	@${RM} -rf ${SRCDIR}/libjava
	@${RM} -rf ${SRCDIR}/libchill
	@${RM} -rf ${SRCDIR}/zlib
	@${RM} -rf ${SRCDIR}/gcc/java
	@${RM} -rf ${SRCDIR}/gcc/testsuite
	@${RM} -rf ${SRCDIR}/gcc/treelang
	@${RM} -rf ${SRCDIR}/libmudflap

pre-configure:
	@${MKDIR} ${CONFIGURE_WRKSRC}

post-install:
.for F in ${BINARIES}
	@${LN} -f ${PREFIX}/bin/${TARGET}-$F ${PREFIX}/${TARGET}/bin/$F
.endfor
	@cd ${PREFIX}/${TARGET}/lib && ${LN} -f libstdcxx.a libstdc++.a
	@cd ${PREFIX}/${TARGET}/lib && ${LN} -f libstdcxx.la libstdc++.la

.include <bsd.port.post.mk>

# Created by: Iblis Lin <iblis@hs.ntnu.edu.tw>
# $FreeBSD$

PORTNAME=	julia
PORTVERSION=	0.7.0
DISTVERSIONSUFFIX=	-full
PORTREVISION=	2
CATEGORIES=	lang math
MASTER_SITES=	https://github.com/JuliaLang/julia/releases/download/v${PORTVERSION}/
PKGNAMESUFFIX=	07

MAINTAINER=	iblis@hs.ntnu.edu.tw
COMMENT=	Julia Language: A fresh approach to technical computing

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

ONLY_FOR_ARCHS=	amd64 i386

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libgit2.so:devel/libgit2 \
		libgmp.so:math/gmp \
		libmbedtls.so:security/mbedtls \
		libmpfr.so:math/mpfr \
		libopenblasp.so:math/openblas \
		libpcre2-8.so:devel/pcre2 \
		libssh2.so:security/libssh2 \
		libutf8proc.so:textproc/utf8proc
BUILD_DEPENDS=	patchelf:sysutils/patchelf \
		pcre2-config:devel/pcre2 \
		cmake:devel/cmake

USES=		gmake compiler:c++11-lib fortran python:2.7,build perl5
USE_LDCONFIG=	yes

WRKSRC=	${WRKDIR}/${PORTNAME}

ALL_TARGET=	default
INSTALL_TARGET=	install
TEST_TARGET=	test

PLIST_SUB=	VERSION="${PORTVERSION:R}" \
		SOVERSION="${PORTVERSION}"

CXXFLAGS+=	-stdlib=libc++ -std=c++11
MAKE_ARGS+=	prefix=${PREFIX} \
		JCXXFLAGS="${CXXFLAGS}" \
		FORCE_ASSERTIONS=${FORCE_ASSERTIONS} \
		USE_GPL_LIBS=${USE_GPL_LIBS} \
		USE_SYSTEM_BLAS=1 \
		USE_SYSTEM_CURL=1 \
		USE_SYSTEM_GMP=1 \
		USE_SYSTEM_LAPACK=1 \
		USE_SYSTEM_LIBGIT2=1 \
		USE_SYSTEM_LIBSSH2=1 \
		USE_SYSTEM_LIBUV=0 \
		USE_SYSTEM_MBEDTLS=1 \
		USE_SYSTEM_MPFR=1 \
		USE_SYSTEM_PATCHELF=1 \
		USE_SYSTEM_PCRE=1 \
		USE_SYSTEM_UTF8PROC=1 \
		NO_GIT=1

OPTIONS_DEFINE=	DEBUG DOCS GPL_LIBS DESKTOP NATIVE
OPTIONS_DEFAULT=	SYSLIBM
OPTIONS_GROUP=	PRIVATE
OPTIONS_SINGLE=	LIBM
OPTIONS_SINGLE_LIBM=	SYSLIBM OPENLIBM
OPTIONS_SUB=	yes

LIBM_DESC=	Math library implementation

DEBUG_VARS=	FORCE_ASSERTIONS=1 \
		ALL_TARGET=all
DEBUG_MAKE_ARGS=	BUNDLE_DEBUG_LIBS=1

PORTDOCS=	html
DOCS_VARS=	INSTALL_TARGET+=install-docs

GPL_LIBS_DESC=	Build with GPL lib: SUITESPARSE
GPL_LIBS_MAKE_ARGS=	USE_SYSTEM_SUITESPARSE=0
GPL_LIBS_VARS=	USE_GPL_LIBS=1

DESKTOP_DESC=	Install icon, .desktop and appdata files
DESKTOP_VARS=	INSTALL_TARGET+=install-desktop \
		INSTALLS_ICONS=yes

SYSLIBM_DESC=	Build with system libm
SYSLIBM_MAKE_ARGS=	USE_SYSTEM_LIBM=1

OPENLIBM_DESC=	Build with OpenLibm (math/openlibm)
OPENLIBM_MAKE_ARGS=	USE_SYSTEM_OPENLIBM=1
OPENLIBM_LIB_DEPENDS=	libopenlibm.so:math/openlibm

.include <bsd.port.options.mk>

NATIVE_DESC=		Build with native CPU JIT tuning
.if ${PORT_OPTIONS:MNATIVE}
MAKE_ARGS+=	JULIA_CPU_TARGET=native
.else
.if ${ARCH} == "amd64"
MAKE_ARGS+=	JULIA_CPU_TARGET=x86-64
.elif ${ARCH} == "i386"
MAKE_ARGS+=	JULIA_CPU_TARGET=pentium4
.else
MAKE_ARGS+=	JULIA_CPU_TARGET=generic
.endif
.endif  # .if ${PORT_OPTIONS:MNATIVE}

.if ${ARCH} == "i386"
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-ui_Makefile
.endif

post-configure:
	${CC} ${CFLAGS} -lopenblas ${LDFLAGS} -o ${WRKSRC}/check_openblas \
		${FILESDIR}/check_openblas.c
	${WRKSRC}/check_openblas && ( \
		echo "USE_BLAS64=1" >> ${WRKSRC}/Make.user \
	) || ( \
		echo "USE_BLAS64=0" >> ${WRKSRC}/Make.user \
	)

.include <bsd.port.mk>

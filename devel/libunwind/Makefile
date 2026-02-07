PORTNAME=	libunwind
PORTVERSION=	20250904	# This is the release date on https://github.com/libunwind/libunwind/releases
CATEGORIES=	devel
MASTER_SITES=	https://github.com/libunwind/libunwind/releases/download/v${LIBUNWIND_VERSION}/
DISTNAME=	libunwind-${LIBUNWIND_VERSION}

PATCH_SITES=	https://github.com/libunwind/libunwind/commit/
PATCHFILES=	b841b2a2665da25dd28fd16977a77bf8b3494dc7.patch:-p1 \
		2ad7f439d6d04a808947e04b07e1efb34371c8b2.patch:-p1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generic stack unwinding library
WWW=		https://github.com/libunwind/libunwind \
		https://www.nongnu.org/libunwind/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386 powerpc powerpc64 powerpc64le

USES=		compiler:c11 cpe libtool pkgconfig

CONFIGURE_ARGS=	--disable-cxx-exceptions \
		--disable-unwind-header \
		ac_cv_path_LATEX2MAN=${TRUE} \
		${CONFIGURE_ARGS_${ARCH}}
CONFIGURE_ARGS_armv7=	ac_cv_search__Unwind_Resume="-lgcc_s -lgcc"

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
TESTING_UNSAFE=	1 test (Gtest-concurrent and/or Ltest-concurrent) fails rarely due to race condition https://github.com/libunwind/libunwind/issues/715
USE_LDCONFIG=	yes

PLIST_SUB=	ARCH=${ARCH:S|amd64|x86_64|:C|armv.|arm|:S|i386|x86|:C|powerpc64.*|ppc64|:S|powerpc|ppc32|}

CPE_VENDOR=	libunwind_project

LIBUNWIND_VERSION=	1.8.3

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc*}
PLIST_SUB+=	COREDUMP="@comment "
.else
PLIST_SUB+=	COREDUMP=""
.endif

post-install:
	cd ${STAGEDIR}${PREFIX}/ && ${FIND} libexec/libunwind -type f >> ${TMPPLIST}

.include <bsd.port.mk>

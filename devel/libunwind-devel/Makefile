PORTNAME=	libunwind
PORTVERSION=	g20261022
CATEGORIES=	devel
PKGNAMESUFFIX=	-devel

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Generic stack unwinding library (development version)
WWW=		https://github.com/libunwind/libunwind \
		https://www.nongnu.org/libunwind/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386 powerpc powerpc64 powerpc64le

CONFLICTS=	libunwind

USES=		autoreconf compiler:c11 cpe libtool pkgconfig

CONFIGURE_ARGS=	--disable-cxx-exceptions \
		--disable-unwind-header \
		ac_cv_path_LATEX2MAN=${TRUE} \
		${CONFIGURE_ARGS_${ARCH}}
CONFIGURE_ARGS_armv7=	ac_cv_search__Unwind_Resume="-lgcc_s -lgcc"

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_TAGNAME=	6b186af8553eb8e15bd42691c92bc0c895a154fe

PLIST_SUB=	ARCH=${ARCH:S|amd64|x86_64|:C|armv.|arm|:S|i386|x86|:C|powerpc64.*|ppc64|:S|powerpc|ppc32|}

CPE_VENDOR=	libunwind_project

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc*}
PLIST_SUB+=	COREDUMP="@comment "
.else
PLIST_SUB+=	COREDUMP=""
.endif

post-install:
	cd ${STAGEDIR}${PREFIX}/ && ${FIND} libexec/libunwind -type f -delete

.include <bsd.port.mk>

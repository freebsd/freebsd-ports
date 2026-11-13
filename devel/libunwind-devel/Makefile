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

LIBUNWIND_PREFIX=${PREFIX}/libunwind11

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

LIBUNWIND_ARCH=	${ARCH:S|amd64|x86_64|:C|armv.|arm|:S|i386|x86|:C|powerpc64.*|ppc64|:S|powerpc|ppc32|}
PLIST_SUB=	ARCH=${LIBUNWIND_ARCH}
MANDIRS=	${LIBUNWIND_PREFIX}/share/man

CPE_VENDOR=	libunwind_project

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc*}
PLIST_SUB+=	COREDUMP="@comment "
.else
PLIST_SUB+=	COREDUMP=""
.endif

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/libexec/libunwind
	@${MKDIR} ${STAGEDIR}${LIBUNWIND_PREFIX}/include \
		${STAGEDIR}${LIBUNWIND_PREFIX}/lib \
		${STAGEDIR}${LIBUNWIND_PREFIX}/libdata/pkgconfig \
		${STAGEDIR}${LIBUNWIND_PREFIX}/share/man/man3
	${MV} ${STAGEDIR}${PREFIX}/include/libunwind*.h \
		${STAGEDIR}${LIBUNWIND_PREFIX}/include/
	${MV} ${STAGEDIR}${PREFIX}/share/man/man3/*.3 \
		${STAGEDIR}${LIBUNWIND_PREFIX}/share/man/man3/
	${MV} ${STAGEDIR}${PREFIX}/libdata/pkgconfig/libunwind*.pc \
		${STAGEDIR}${LIBUNWIND_PREFIX}/libdata/pkgconfig/
	cd ${STAGEDIR}${PREFIX}/lib && \
		for f in libunwind*; do \
			case "$${f}" in \
			*.so.11|*.so.11.*) continue ;; \
			esac; \
			${MV} "$${f}" ${STAGEDIR}${LIBUNWIND_PREFIX}/lib/; \
		done
	${LN} -sf ../../lib/libunwind.so.11 \
		${STAGEDIR}${LIBUNWIND_PREFIX}/lib/libunwind.so
	${LN} -sf ../../lib/libunwind-${LIBUNWIND_ARCH}.so.11 \
		${STAGEDIR}${LIBUNWIND_PREFIX}/lib/libunwind-${LIBUNWIND_ARCH}.so
	${REINPLACE_CMD} -e 's|^prefix=.*|prefix=${LIBUNWIND_PREFIX}|' \
		${STAGEDIR}${LIBUNWIND_PREFIX}/libdata/pkgconfig/*.pc

.include <bsd.port.mk>

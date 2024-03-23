PORTNAME=	libunwind
PORTVERSION=	20240221	# This is the release date on https://github.com/libunwind/libunwind/releases
CATEGORIES=	devel
MASTER_SITES=	https://github.com/libunwind/libunwind/releases/download/v${LIBUNWIND_VERSION}/
DISTNAME=	libunwind-${LIBUNWIND_VERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generic stack unwinding library
WWW=		https://github.com/libunwind/libunwind \
		https://www.nongnu.org/libunwind/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386 powerpc powerpc64 powerpc64le

USES=		compiler:c11 cpe libtool pathfix pkgconfig

CONFIGURE_ARGS=	--disable-cxx-exceptions \
		--disable-unwind-header \
		ac_cv_path_LATEX2MAN=${TRUE}
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PLIST_SUB=	ARCH=${ARCH:S|amd64|x86_64|:C|armv.|arm|:S|i386|x86|:C|powerpc64.*|ppc64|:S|powerpc|ppc32|}

CPE_VENDOR=	libunwind_project

LIBUNWIND_VERSION=	1.8.1

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc*}
PLIST_SUB+=	COREDUMP="@comment "
.else
PLIST_SUB+=	COREDUMP=""
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1400052
PLIST_FILES=	include/unwind.h
.endif

post-install:
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1400052
	${INSTALL_DATA} ${FILESDIR}/unwind.h ${STAGEDIR}${PREFIX}/include
.endif
	cd ${STAGEDIR}${PREFIX}/ && ${FIND} libexec/libunwind -type f >> ${TMPPLIST}

.include <bsd.port.mk>

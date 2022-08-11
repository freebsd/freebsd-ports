PORTNAME=	libunwind
PORTVERSION=	20211201	# This is the release date on https://download.savannah.gnu.org/releases/libunwind/
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SAVANNAH \
		https://github.com/libunwind/libunwind/releases/download/v${PORTVERSION}/
DISTNAME=	${PORTNAME}-1.6.2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generic stack unwinding library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386 powerpc64 powerpc64le

USES=		compiler:c11 cpe libtool pathfix pkgconfig

CONFIGURE_ARGS=	--disable-cxx-exceptions \
		--disable-unwind-header \
		ac_cv_path_LATEX2MAN=${TRUE}
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PLIST_SUB=	ARCH=${ARCH:S|amd64|x86_64|:C|armv.|arm|:S|i386|x86|:C|powerpc64.*|ppc64|}

CPE_VENDOR=	libunwind_project

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc64*}
PLIST_SUB+=	COREDUMP="@comment "
.else
PLIST_SUB+=	COREDUMP=""
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1400052
PLIST_FILES=	include/unwind.h

post-install:
	${INSTALL_DATA} ${FILESDIR}/unwind.h ${STAGEDIR}${PREFIX}/include
.endif

.include <bsd.port.mk>

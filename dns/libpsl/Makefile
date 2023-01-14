PORTNAME=	libpsl
DISTVERSION=	0.21.2
CATEGORIES=	dns
MASTER_SITES=	https://github.com/rockdaboot/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C library to handle the Public Suffix List
WWW=		https://github.com/rockdaboot/libpsl

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	public_suffix_list>=0:dns/public_suffix_list

USES=		localbase:ldflags meson pkgconfig python:build shebangfix tar:lz

USE_LDCONFIG=	yes
USE_LOCALE=	en_US.UTF-8

SHEBANG_FILES=	src/psl-make-dafsa
TEST_TARGET=	test

MESON_ARGS=	-Ddefault_library=both \
		-Dpsl_file=${LOCALBASE}/share/public_suffix_list/public_suffix_list.dat \
		-Dpsl_testfile=${LOCALBASE}/share/public_suffix_list/test_psl.txt

OPTIONS_SINGLE=		IDNA
OPTIONS_SINGLE_IDNA=	ICU IDN2
OPTIONS_DEFAULT=	ICU

ICU_DESC=		Use devel/icu (IDNA2008 UTS\#46 library)
IDN2_DESC=		Use dns/libidn2 (IDNA2008 library)

ICU_LIB_DEPENDS=	libicuuc.so:devel/icu
ICU_MESON_ON=		-Druntime=libicu
IDN2_USES=		iconv
IDN2_LIB_DEPENDS=	libidn2.so:dns/libidn2 \
			libunistring.so:devel/libunistring
IDN2_MESON_ON=		-Druntime=libidn2

.include <bsd.port.mk>

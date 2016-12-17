# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libpsl
PORTVERSION=	0.16.1
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	dns

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C library to handle the Public Suffix List

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	public_suffix_list>=0:dns/public_suffix_list \
		xsltproc:textproc/libxslt

OPTIONS_DEFINE=	NLS
OPTIONS_SINGLE=	IDNA
OPTIONS_SINGLE_IDNA=	ICU IDN IDN2
OPTIONS_DEFAULT=ICU
ICU_DESC=	Use devel/icu (IDNA2008 UTS\#46 library)
IDN_DESC=	Use dns/libidn (IDNA2003 library)
IDN2_DESC=	Use dns/libidn2 (IDNA2008 library)

CONFIGURE_ARGS=	--enable-man \
		--with-psl-file=${LOCALBASE}/share/public_suffix_list/public_suffix_list.dat \
		--with-psl-testfile=${LOCALBASE}/share/public_suffix_list/test_psl.txt
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		autoreconf libtool pathfix pkgconfig python:build shebangfix

GH_ACCOUNT=	rockdaboot
USE_GITHUB=	yes

SHEBANG_FILES=	src/psl-make-dafsa

ICU_CONFIGURE_ON=	--enable-builtin=libicu --enable-runtime=libicu
ICU_LIB_DEPENDS=	libicuuc.so:devel/icu
IDN_CONFIGURE_ON=	--enable-builtin=libidn --enable-runtime=libidn
IDN_LIB_DEPENDS=	libidn.so:dns/libidn \
			libunistring.so:devel/libunistring
IDN_USES=		iconv
IDN2_CONFIGURE_ON=	--enable-builtin=libidn2 --enable-runtime=libidn2
IDN2_LIB_DEPENDS=	libidn2.so:dns/libidn2 \
			libunistring.so:devel/libunistring
IDN2_USES=		iconv
NLS_CPPFLAGS=		-DENABLE_NLS=1
NLS_USES=		gettext
NLS_USES_OFF=		gettext-tools

.include <bsd.port.mk>

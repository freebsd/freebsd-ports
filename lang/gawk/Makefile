# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	gawk
PORTVERSION=	5.0.0
CATEGORIES=	lang
MASTER_SITES=	GNU

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	GNU version of AWK scripting language

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsigsegv.so:devel/libsigsegv

OPTIONS_DEFINE=		NLS MPFR
OPTIONS_SUB=		yes
NLS_USES=		gettext
NLS_CONFIGURE_OFF=	--disable-nls
MPFR_DESC?=		Support multiple-precision floating-point computation
MPFR_LIB_DEPENDS=	libmpfr.so:math/mpfr
MPFR_CONFIGURE_OFF=	--without-gmp --without-mpfr

INFO=		gawk gawkinet gawkworkflow

GNU_CONFIGURE=	yes
USES=		iconv libtool makeinfo readline tar:xz
CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG} \
		--with-libintl-prefix=${LOCALBASE} \
		AWK=${AWK}
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

PLIST_SUB+=	VERSION=${PORTVERSION}

post-patch:
	@${RM} ${WRKSRC}/doc/*.info
	@${REINPLACE_CMD} -e 's/ -export-dynamic/ -Wl,--export-dynamic/' \
		${WRKSRC}/configure

.include <bsd.port.mk>

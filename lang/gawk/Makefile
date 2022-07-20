PORTNAME=	gawk
PORTVERSION=	5.1.1
CATEGORIES=	lang
MASTER_SITES=	GNU

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	GNU version of AWK scripting language

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsigsegv.so:devel/libsigsegv

CONFLICTS_INSTALL=	ja-gawk # bin/gawk

OPTIONS_DEFINE=		NLS MPFR
OPTIONS_SUB=		yes
NLS_USES=		gettext
NLS_CONFIGURE_OFF=	--disable-nls
MPFR_DESC?=		Support multiple-precision floating-point computation
MPFR_LIB_DEPENDS=	libgmp.so:math/gmp libmpfr.so:math/mpfr
MPFR_CONFIGURE_OFF=	--without-gmp --without-mpfr

INFO=		gawk gawkinet gawkworkflow

GNU_CONFIGURE=	yes
USES=		iconv libtool makeinfo readline tar:lz
CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG} \
		--with-libintl-prefix=${LOCALBASE} \
		AWK=${AWK}
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

PLIST_SUB+=	VERSION=${PORTVERSION}

post-patch:
	@${RM} ${WRKSRC}/doc/*.info

.include <bsd.port.mk>

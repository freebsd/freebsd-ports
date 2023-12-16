PORTNAME=	gawk
PORTVERSION=	5.3.0
CATEGORIES=	lang
MASTER_SITES=	GNU

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	GNU version of AWK scripting language
WWW=		https://www.gnu.org/software/gawk/gawk.html

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS_INSTALL=	ja-gawk # bin/gawk

OPTIONS_DEFINE=		NLS MPFR
OPTIONS_SUB=		yes
NLS_USES=		gettext
NLS_CONFIGURE_OFF=	--disable-nls
MPFR_DESC?=		Support multiple-precision floating-point computation
MPFR_LIB_DEPENDS=	libgmp.so:math/gmp libmpfr.so:math/mpfr
MPFR_CONFIGURE_OFF=	--without-gmp --without-mpfr

INFO=		gawk gawkinet gawkworkflow pm-gawk

GNU_CONFIGURE=	yes
USES=		gmake iconv libtool readline tar:lz
CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG} \
		--with-libintl-prefix=${LOCALBASE} \
		AWK=${AWK}
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

PLIST_SUB+=	VERSION=${PORTVERSION}

.include <bsd.port.mk>

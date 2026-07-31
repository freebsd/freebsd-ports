PORTNAME=	gawk
PORTVERSION=	5.4.1
CATEGORIES=	lang
MASTER_SITES=	GNU

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	GNU version of AWK scripting language
WWW=		https://www.gnu.org/software/gawk/gawk.html

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS_INSTALL=	ja-gawk # bin/gawk

USES=		gmake iconv libtool readline tar:lz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG} \
		--with-libintl-prefix=${LOCALBASE} \
		AWK=${AWK}
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

INFO=		gawk gawkinet gawknotes gawkworkflow pm-gawk
PLIST_SUB+=	VERSION=${PORTVERSION}
PORTDOCS=	AUTHORS ChangeLog* NEWS* POSIX.STD README TODO

OPTIONS_DEFINE=	DOCS MPFR NLS
OPTIONS_SUB=	yes

MPFR_DESC=	Multiple-precision floating-point support
MPFR_LIB_DEPENDS=	libgmp.so:math/gmp libmpfr.so:math/mpfr
MPFR_CONFIGURE_OFF=	--without-gmp --without-mpfr

NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-nls

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

PORTNAME=	fmptools
DISTVERSION=	0.2.2
CATEGORIES=	databases
MASTER_SITES=	https://github.com/evanmiller/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	walker.thompson@urz.uni-heidelberg.de
COMMENT=	Convert FileMaker Pro databases to several convenient formats
WWW=		https://github.com/evanmiller/fmptools

LICENSE=	MIT

USES=		iconv libtool localbase:ldflags
GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	JSON SQLITE XLSX 
OPTIONS_DEFAULT=JSON SQLITE XLSX
OPTIONS_SUB=	yes

XLSX_DESC=	Excel export support via libxlsxwriter

JSON_LIB_DEPENDS=	libyajl.so:devel/yajl
JSON_CONFIGURE_ENV_OFF=	ac_cv_lib_yajl_yajl_gen_alloc=no

SQLITE_USES=		sqlite:3
SQLITE_CONFIGURE_ENV_OFF=	ac_cv_lib_sqlite3_sqlite3_open_v2=no

XLSX_LIB_DEPENDS=	libxlsxwriter.so:math/libxlsxwriter
XLSX_CONFIGURE_ENV_OFF=	ac_cv_lib_xlsxwriter_workbook_new=no

post-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/.libs/fmpdump ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

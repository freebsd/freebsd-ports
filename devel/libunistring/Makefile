PORTNAME=	libunistring
DISTVERSION=	1.2
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	takefu@airport.fm
COMMENT=	Unicode string library
WWW=		https://www.gnu.org/software/libunistring/

LICENSE=	GFDL GPLv2 LGPL3+
LICENSE_COMB=	multi
LICENSE_FILE_GFDL=	${WRKSRC}/doc/libunistring.texi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL3+ =	${WRKSRC}/COPYING.LIB

USES=		alias charsetfix cpe iconv libtool tar:xz
CPE_VENDOR=	gnu
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
INFO=		${PORTNAME}
OPTIONS_DEFINE=	DOCS

TESTING_UNSAFE=	test-time.c:46: assertion 'tt3 >= tv2.tv_sec' failed

.include <bsd.port.mk>

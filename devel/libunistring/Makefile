PORTNAME=	libunistring
DISTVERSION=	1.4
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

.include <bsd.port.mk>

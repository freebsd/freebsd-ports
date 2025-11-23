PORTNAME=	ding-libs
PORTVERSION=	0.6.2
CATEGORIES=	devel
MASTER_SITES=	https://github.com/SSSD/ding-libs/releases/download/${PORTVERSION}/

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Collection of useful libraries for developers
WWW=		https://github.com/SSSD/ding-libs/

LICENSE=	GPLv3+ LGPL3+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING
LICENSE_FILE_LGPL3+ =	${WRKSRC}/COPYING.LESSER

USES=		iconv gettext-runtime libtool localbase
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
CONFIGURE_ENV=	DOXYGEN=""
LIBS+=		${ICONV_LIB} -lintl
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS TEST

# libcheck is required to run *all* the unit tests.
# Without it only 14/20 tests will run.
TEST_BUILD_DEPENDS=	check>=0:devel/check
TEST_USES=		pkgconfig

.include <bsd.port.mk>

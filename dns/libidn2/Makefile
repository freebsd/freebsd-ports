PORTNAME=	libidn2
PORTVERSION=	2.3.7
CATEGORIES=	dns
MASTER_SITES=	GNU/libidn

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implementation of IDNA2008 internationalized domain names
WWW=		https://www.gnu.org/software/libidn/\#libidn2 \
		https://gitlab.com/libidn/libidn2

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	help2man:misc/help2man
LIB_DEPENDS=	libunistring.so:devel/libunistring

USES=		charsetfix iconv libtool localbase makeinfo pathfix

CONFIGURE_ARGS=	--disable-nls \
		--enable-ld-version-script \
		--with-libunistring-prefix=${LOCALBASE} \
		ac_cv_prog_RONN=${TRUE}
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
LDFLAGS+=	-Wl,--undefined-version
TEST_TARGET=	check
USE_LDCONFIG=	yes

INFO=		libidn2

.include <bsd.port.mk>

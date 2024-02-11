PORTNAME=	libidn2
DISTVERSION=	2.3.7
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
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

LDFLAGS+=	-Wl,--undefined-version

INFO=		libidn2
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

CONFIGURE_ARGS=	--disable-nls \
		--with-libunistring-prefix=${LOCALBASE} \
		--enable-ld-version-script \
		ac_cv_prog_RONN=${TRUE}

.include <bsd.port.mk>

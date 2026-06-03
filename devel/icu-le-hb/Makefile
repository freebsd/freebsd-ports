PORTNAME=	icu-le-hb
PORTVERSION=	2.0.0
CATEGORIES=	devel print

MAINTAINER=	office@FreeBSD.org
COMMENT=	ICU Layout Engine API on top of HarfBuzz shaping library
WWW=		https://www.freedesktop.org/wiki/Software/HarfBuzz/

LICENSE=	ICU
LICENSE_NAME=	ICU license
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libicuuc.so:devel/icu \
		libharfbuzz.so:print/harfbuzz

USE_GITHUB=	yes
GH_ACCOUNT=	harfbuzz

USES=		autoreconf compiler:c++11-lib gmake libtool pathfix pkgconfig
USE_CXXSTD=	gnu++11
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>

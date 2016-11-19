# $FreeBSD$

PORTNAME=	icu-le-hb
PORTVERSION=	1.0.3
CATEGORIES=	devel print
MASTER_SITES=	http://www.freedesktop.org/software/harfbuzz/release/

MAINTAINER=	office@FreeBSD.org
COMMENT=	ICU Layout Engine API on top of HarfBuzz shaping library

LICENSE=	ICU
LICENSE_NAME=	ICU license
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libicuuc.so:devel/icu \
		libharfbuzz.so:print/harfbuzz

USES=		gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>

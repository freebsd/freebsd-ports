PORTNAME=	vali
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.1
CATEGORIES=	devel
MASTER_SITES=	https://gitlab.freedesktop.org/emersion/${PORTNAME}/-/releases/${DISTVERSIONFULL}/downloads/
DISTNAME=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	C library and code generator for Varlink
WWW=		https://gitlab.freedesktop.org/emersion/vali

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libaml.so:devel/aml \
		libjson-c.so:devel/json-c

USES=		meson pkgconfig
USE_LDCONFIG=	yes

PLIST_FILES=	bin/${PORTNAME} \
		include/${PORTNAME}.h \
		lib/lib${PORTNAME}.so \
		lib/lib${PORTNAME}.so.${DISTVERSION} \
		lib/lib${PORTNAME}.so.1 \
		libdata/pkgconfig/${PORTNAME}.pc

.include <bsd.port.mk>

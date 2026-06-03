PORTNAME=	libscfg
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
CATEGORIES=	devel
MASTER_SITES=	https://codeberg.org/emersion/${PORTNAME}/releases/download/${DISTVERSIONFULL}/
DISTNAME=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	C library for a simple configuration file format
WWW=		https://codeberg.org/emersion/libscfg

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		meson pkgconfig
USE_LDCONFIG=	yes

PLIST_FILES=	include/${PORTNAME:S/lib//}.h \
		lib/${PORTNAME}.so \
		lib/${PORTNAME}.so.${DISTVERSION} \
		lib/${PORTNAME}.so.2 \
		libdata/pkgconfig/${PORTNAME:S/lib//}.pc

.include <bsd.port.mk>

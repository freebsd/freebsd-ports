PORTNAME=	libscfg
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.1
CATEGORIES=	devel
MASTER_SITES=	https://git.sr.ht/~emersion/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	C library for a simple configuration file format
WWW=		https://sr.ht/~emersion/libscfg/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		meson pkgconfig
USE_LDCONFIG=	yes
PLIST_FILES=	include/${PORTNAME:S/lib//}.h \
		lib/${PORTNAME}.so \
		libdata/pkgconfig/${PORTNAME:S/lib//}.pc

.include <bsd.port.mk>

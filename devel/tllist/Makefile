PORTNAME=	tllist
DISTVERSION=	1.1.0
CATEGORIES=	devel
MASTER_SITES=	https://codeberg.org/dnkl/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	C header file only implementation of a typed linked list
WWW=		https://codeberg.org/dnkl/tllist

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		meson
USE_CSTD=	gnu99
WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	include/${PORTNAME}.h \
		libdata/pkgconfig/${PORTNAME}.pc

.include <bsd.port.mk>

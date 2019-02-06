# $FreeBSD$

PORTNAME=	mujs
DISTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES=	lang devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Embeddable Javascript interpreter in C

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake localbase:ldflags readline
USE_GITHUB=	yes
GH_ACCOUNT=	ccxvii
USE_LDCONFIG=	yes
ALL_TARGET=	default

PLIST_FILES=	bin/mujs \
		include/mujs.h \
		lib/libmujs.so \
		libdata/pkgconfig/mujs.pc

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmujs.so

.include <bsd.port.mk>

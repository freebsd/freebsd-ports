# $FreeBSD$

PORTNAME=	mujs
DISTVERSION=	1.0.5-10
DISTVERSIONSUFFIX=	-g9f40dfb
CATEGORIES=	lang devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Embeddable Javascript interpreter in C

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 gmake localbase:ldflags readline # c11 is induced by the FreeBSD headers via isnan(3), etc, otherwise the project is all c99 code
USE_GITHUB=	yes
GH_ACCOUNT=	ccxvii
USE_LDCONFIG=	yes
ALL_TARGET=	shared
INSTALL_TARGET=	install-shared

PLIST_FILES=	bin/mujs \
		include/mujs.h \
		lib/libmujs.so \
		libdata/pkgconfig/mujs.pc

post-install: # https://github.com/ccxvii/mujs/issues/83
	@${REINPLACE_CMD} -i '' 's|${STAGEDIR}||' ${STAGEDIR}${PREFIX}/libdata/pkgconfig/mujs.pc

.include <bsd.port.mk>

PORTNAME=	yascreen
DISTVERSIONPREFIX=	v
DISTVERSION=	2.14
CATEGORIES=	devel

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Curses replacement library for daemons and embedded apps
WWW=		https://github.com/bbonev/yascreen

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	bbonev
USE_LDCONFIG=	yes

MAKE_ARGS=	DEBUG="" PREFIX=${PREFIX}
ALL_TARGET=	libyascreen.a libyascreen.so yascreen.pc

PLIST_FILES=	include/yascreen.h \
		lib/libyascreen.a \
		lib/libyascreen.so \
		lib/libyascreen.so.0 \
		lib/libyascreen.so.0.0.0 \
		libdata/pkgconfig/yascreen.pc

do-install:
	${INSTALL_DATA} ${WRKSRC}/yascreen.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libyascreen.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libyascreen.so.0.0.0 ${STAGEDIR}${PREFIX}/lib
	${LN} -sf libyascreen.so.0.0.0 ${STAGEDIR}${PREFIX}/lib/libyascreen.so.0
	${LN} -sf libyascreen.so.0 ${STAGEDIR}${PREFIX}/lib/libyascreen.so
	${INSTALL_DATA} ${WRKSRC}/yascreen.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>

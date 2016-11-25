# $FreeBSD$

PORTNAME=	libcrossguid
PORTVERSION=	20150803
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	mickael.maillot@gmail.com
COMMENT=	Minimal and cross platform C++ GUID library

LICENSE=	MIT
LICENSE_FILES=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid

USE_GITHUB=	yes
GH_ACCOUNT=	graeme-hill
GH_PROJECT=	crossguid
GH_TAGNAME=	8f399e8

USES=		compiler:c++11-lang pkgconfig
USE_CXXSTD=	c++11
CXXFLAGS+=	`pkg-config --cflags uuid`
USE_LDCONFIG=	yes

PLIST_FILES=	include/guid.h \
		lib/libcrossguid.so \
		lib/libcrossguid.so.0 \
		libdata/pkgconfig/libcrossguid.pc

post-patch:
	@${SED} -e 's|%PREFIX%|${PREFIX}|' -e 's|%VERSION%|${PORTVERSION}|' \
		${FILESDIR}/libcrossguid.pc.in > ${WRKDIR}/libcrossguid.pc

do-build:
	cd ${WRKSRC} && ${CXX} ${CXXFLAGS} -shared -fPIC -Wl,-soname,libcrossguid.so.0 \
		-DGUID_LIBUUID -L${LOCALBASE}/lib guid.cpp -o libcrossguid.so.0 -luuid

do-install:
	${INSTALL_DATA} ${WRKSRC}/guid.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/libcrossguid.so.0 ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKDIR}/libcrossguid.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig
	${LN} -sf libcrossguid.so.0 ${STAGEDIR}${PREFIX}/lib/libcrossguid.so

.include <bsd.port.mk>

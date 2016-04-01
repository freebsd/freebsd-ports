# $FreeBSD$

PORTNAME=	libcrossguid
PORTVERSION=	20150803
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
PLIST_FILES=	include/guid.h lib/libcrossguid.so libdata/pkgconfig/libcrossguid.pc

post-patch:
	@${SED} -e 's|%PREFIX%|${PREFIX}|g ; s|%VERSION%|${PORTVERSION}|g' \
		${FILESDIR}/libcrossguid.pc.in > ${WRKDIR}/libcrossguid.pc

do-build:
	@cd ${WRKSRC} && ${CXX} ${CXXFLAGS} -shared -fPIC guid.cpp -o libcrossguid.so -DGUID_LIBUUID

do-install:
	${INSTALL_DATA} ${WRKSRC}/guid.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/libcrossguid.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKDIR}/libcrossguid.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>

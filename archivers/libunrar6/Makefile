# $FreeBSD$

PORTNAME=	libunrar6
PORTVERSION=	6.0.4
CATEGORIES=	archivers
MASTER_SITES=	http://www.rarlab.com/rar/
DISTNAME=	unrarsrc-${PORTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	RAR archive extraction library

LICENSE=	UNRAR
LICENSE_NAME=	UnRAR License
LICENSE_FILE=	${WRKSRC}/license.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		compiler:c++11-lang gmake
USE_LDCONFIG=	yes

ALL_TARGET=	lib
MAKEFILE=	makefile
MAKE_ARGS=	AR="${AR}" \
		CXX="${CXX}" \
		CXXFLAGS="${CXXFLAGS} -fPIC" \
		LDFLAGS="-Wl,-soname,${SONAME} -pthread ${LDFLAGS}" \
		STRIP="${STRIP_CMD}"
SONAME=		libunrar.so.6
WRKSRC=		${WRKDIR}/unrar

CONFLICTS_INSTALL=	libunrar-3*

OPTIONS_DEFINE=		OPENSSL_AES
OPTIONS_DEFAULT=	OPENSSL_AES

OPENSSL_AES_DESC=	Use OpenSSL implementation of AES
OPENSSL_AES_CPPFLAGS=	-DOPENSSL_AES -I${OPENSSLINC}
OPENSSL_AES_LDFLAGS=	-L${OPENSSLLIB} -lcrypto
OPENSSL_AES_USES=	ssl

PLIST_FILES=	lib/libunrar.a \
		lib/libunrar.so \
		lib/${SONAME} \
		include/${PORTNAME}/dll.hpp

do-install:
	${INSTALL_DATA} ${WRKSRC}/libunrar.a ${STAGEDIR}${PREFIX}/lib/libunrar.a
	${INSTALL_LIB} ${WRKSRC}/libunrar.so ${STAGEDIR}${PREFIX}/lib/${SONAME}
	${RLN} ${STAGEDIR}${PREFIX}/lib/${SONAME} ${STAGEDIR}${PREFIX}/lib/${SONAME:R}
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/dll.hpp ${STAGEDIR}${PREFIX}/include/${PORTNAME}/dll.hpp

.include <bsd.port.mk>

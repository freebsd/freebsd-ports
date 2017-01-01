# $FreeBSD$

PORTNAME=	libunrar5
PORTVERSION=	5.4.5
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://www.rarlab.com/rar/
DISTNAME=	unrarsrc-${PORTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	RAR archive extraction library

LICENSE=	UNRAR
LICENSE_NAME=	UnRAR License
LICENSE_FILE=	${WRKSRC}/license.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		gmake
USE_LDCONFIG=	yes

ALL_TARGET=	lib liba
MAKEFILE=	makefile
MAKE_ARGS=	AR="${AR}" \
		CXX="${CXX}" \
		CXXFLAGS="${CXXFLAGS} -fPIC" \
		LDFLAGS="-Wl,-soname,${SONAME} -pthread ${LDFLAGS}" \
		STRIP="${STRIP_CMD}"
SONAME=		libunrar.so.5
WRKSRC=		${WRKDIR}/unrar

CONFLICTS_INSTALL=	libunrar-3* libunrar4-4*

OPTIONS_DEFINE=		OPENSSL_AES
OPTIONS_DEFAULT=	OPENSSL_AES

OPENSSL_AES_DESC=	Use OpenSSL implementation of AES
OPENSSL_AES_CPPFLAGS=	-DOPENSSL_AES -I${OPENSSLINC}
OPENSSL_AES_LDFLAGS=	-L${OPENSSLLIB} -lcrypto
OPENSSL_AES_USES=	ssl

PLIST_FILES=	lib/libunrar.a \
		lib/libunrar.so \
		lib/${SONAME} \
		include/libunrar5/dll.hpp

do-install:
	${INSTALL_DATA} ${WRKSRC}/libunrar.a ${STAGEDIR}${PREFIX}/lib/libunrar.a
	${INSTALL_LIB} ${WRKSRC}/libunrar.so ${STAGEDIR}${PREFIX}/lib/${SONAME}
	(cd ${STAGEDIR}${PREFIX}/lib; ${LN} -sf ${SONAME} libunrar.so)
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/libunrar5
	${INSTALL_DATA} ${WRKSRC}/dll.hpp ${STAGEDIR}${PREFIX}/include/libunrar5/dll.hpp

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MOPENSSL_AES} && ${SSL_DEFAULT:Mopenssl-devel}
BROKEN=		OPENSSL_AES option does not build with openssl-devel
.endif

.include <bsd.port.post.mk>

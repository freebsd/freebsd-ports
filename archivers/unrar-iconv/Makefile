PORTNAME=	unrar
PORTVERSION=	6.24
PORTEPOCH=	6
CATEGORIES=	archivers
MASTER_SITES=	https://www.rarlab.com/rar/
PKGNAMESUFFIX=	-iconv
DISTNAME=	unrarsrc-6.2.12

MAINTAINER=	yarodin@gmail.com
COMMENT=	Extract, view & test RAR archives
WWW=		https://www.rarlab.com/

LICENSE=	UNRAR
LICENSE_NAME=	UnRAR license
LICENSE_FILE=	${WRKSRC}/license.txt
LICENSE_PERMS=	auto-accept dist-mirror pkg-mirror

USES=		compiler:c++11-lang cpe iconv

CPPFLAGS+=	-DWITH_ICONV -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB} -lpthread
MAKE_ARGS=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" LDFLAGS="${LDFLAGS}" STRIP="${STRIP_CMD}"
MAKEFILE=	makefile
WRKSRC=		${WRKDIR}/unrar

PLIST_FILES=	bin/unrar

CONFLICTS_INSTALL=	unrar

CPE_VENDOR=	rarlab

OPTIONS_DEFINE=	OPENSSL_AES
OPTIONS_DEFAULT=OPENSSL_AES
OPENSSL_AES_DESC=	Use OpenSSL implementation of AES

OPENSSL_AES_CPPFLAGS=	-DOPENSSL_AES -I${OPENSSLINC}
OPENSSL_AES_LDFLAGS=	${${OPENSSLLIB} == /usr/lib :? :-L${OPENSSLLIB}} -lcrypto
OPENSSL_AES_USES=	ssl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unrar ${STAGEDIR}${PREFIX}/bin/
	@${ECHO_MSG} "===> Added iconv support, see new switches:"
	@${ECHO_MSG} "     la, ll and lo at \"unrar -?\""
	@${ECHO_MSG} "===> REMEMBER!!!: Windows rar archives using old DOS encodings as internal encoding."
	@${ECHO_MSG} "     CP866 for russian lang for example."

.include <bsd.port.mk>

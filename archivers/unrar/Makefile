# Created by: ache
# $FreeBSD$

PORTNAME=	unrar
DISTVERSION=	5.71
PORTREVISION=	1
PORTEPOCH=	6
CATEGORIES+=	archivers
MASTER_SITES=	https://rarlab.com/rar/ \
		LOCAL/sunpoet
DISTNAME=	unrarsrc-5.7.5

MAINTAINER?=	sunpoet@FreeBSD.org
COMMENT=	Extract, view & test RAR archives

LICENSE=	UNRAR
LICENSE_FILE=	${WRKSRC}/license.txt
LICENSE_NAME=	UnRAR license
LICENSE_PERMS=	auto-accept dist-mirror pkg-mirror

USES+=		compiler:c++11-lang

OPTIONS_DEFINE=	OPENSSL_AES
OPTIONS_DEFAULT=OPENSSL_AES
OPENSSL_AES_DESC=	Use OpenSSL implementation of AES

CONFLICTS_INSTALL?=	unrar-iconv

LDFLAGS+=	-lpthread
MAKE_ARGS=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" LDFLAGS="${LDFLAGS}" STRIP="${STRIP_CMD}"
MAKEFILE=	makefile
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/unrar

SLAVEDIRS=	archivers/unrar-iconv

OPENSSL_AES_CPPFLAGS=	-DOPENSSL_AES -I${OPENSSLINC}
OPENSSL_AES_LDFLAGS=	${${OPENSSLLIB} == /usr/lib :? :-L${OPENSSLLIB}} -lcrypto
OPENSSL_AES_USES=	ssl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unrar ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>

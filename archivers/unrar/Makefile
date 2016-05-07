# Created by: ache
# $FreeBSD$

PORTNAME=	unrar
PORTVERSION=	5.31
PORTEPOCH=	5
CATEGORIES+=	archivers
MASTER_SITES=	http://www.rarlab.com/rar/ \
		LOCAL/sunpoet
DISTNAME=	unrarsrc-5.3.11

MAINTAINER?=	sunpoet@FreeBSD.org
COMMENT=	Extract, view & test RAR archives

OPTIONS_DEFINE=	DOCS OPENSSL_AES
OPTIONS_DEFAULT=OPENSSL_AES
OPENSSL_AES_DESC=	Use OpenSSL implementation of AES

CONFLICTS_INSTALL?=	zh-unrar-[0-9].* unrar-iconv-[0-9].*

LDFLAGS+=	-lpthread
MAKE_ARGS=	CXX=${CXX} LDFLAGS="${LDFLAGS}" STRIP=${STRIP_CMD}
MAKEFILE=	makefile
USES+=		gmake
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/unrar
PORTDOCS=	license.txt readme.txt

SLAVEDIRS=	archivers/unrar-iconv chinese/unrar

OPENSSL_AES_CPPFLAGS=	-DOPENSSL_AES -I${OPENSSLINC}
OPENSSL_AES_LDFLAGS=	-L${OPENSSLLIB} -lcrypto
OPENSSL_AES_USE=	OPENSSL=yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unrar ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>

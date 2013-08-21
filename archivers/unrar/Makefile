# Created by: ache
# $FreeBSD$

PORTNAME=	unrar
PORTVERSION=	4.20
PORTREVISION=	1
PORTEPOCH=	5
CATEGORIES+=	archivers
MASTER_SITES=	http://www.rarlab.com/rar/ \
		LOCAL/sunpoet
DISTNAME=	unrarsrc-4.2.4

MAINTAINER?=	sunpoet@FreeBSD.org
COMMENT=	Extract, view & test RAR archives

OPTIONS_DEFINE=	DOCS OPENSSL_AES
OPTIONS_DEFAULT=OPENSSL_AES
OPENSSL_AES_DESC=	Use OpenSSL implementation of AES

CONFLICTS?=	zh-unrar-[0-9].* unrar-iconv-[0-9].*

MAKE_ARGS=	STRIP=${STRIP_CMD}
MAKEFILE=	makefile.unix
USES=		gmake
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/unrar
PORTDOCS=	license.txt readme.txt

SLAVEDIRS=	archivers/unrar-iconv chinese/unrar

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENSSL_AES}
CPPFLAGS+=	-DOPENSSL_AES -I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB} -lcrypto
USE_OPENSSL=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^CXX/ s|^|#|' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unrar ${PREFIX}/bin/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>

# New ports collection makefile for:    unrar
# Date created:         28 Dec 1994
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	unrar
PORTVERSION=	4.20
PORTEPOCH=	5
CATEGORIES+=	archivers
MASTER_SITES=	http://www.rarlab.com/rar/ \
		LOCAL/sunpoet
DISTNAME=	unrarsrc-4.2.1

MAINTAINER?=	sunpoet@FreeBSD.org
COMMENT=	Extract, view & test RAR archives

OPTIONS=	OPENSSL_AES "Use OpenSSL implementation of AES" on

CONFLICTS?=	zh-unrar-[0-9].* unrar-iconv-[0-9].*

MAKE_ARGS=	STRIP=${STRIP_CMD}
MAKEFILE=	makefile.unix
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/unrar
PORTDOCS=	license.txt readme.txt

.include <bsd.port.options.mk>

.if !defined(WITHOUT_OPENSSL_AES)
CPPFLAGS+=	-DOPENSSL_AES -I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB} -lcrypto
USE_OPENSSL=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^CXX/ s|^|#|' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unrar ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>

# Created by: James Bailie <jimmy@mammothcheese.ca>
# $FreeBSD$

PORTNAME=	libdombey
PORTVERSION=	5.34
CATEGORIES=	devel
MASTER_SITES=	http://www.mammothcheese.ca/

MAINTAINER=	jimmy@mammothcheese.ca
COMMENT=	SCGI application server in a library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		ssl
USE_LDCONFIG=	yes
CFLAGS+=	-I${OPENSSLINC}

DESTDIRNAME=	STAGEDIR

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	tentative definition has type 'EVP_CIPHER_CTX' (aka 'struct evp_cipher_ctx_st') that is never completed
BROKEN_FreeBSD_13=	tentative definition has type 'EVP_CIPHER_CTX' (aka 'struct evp_cipher_ctx_st') that is never completed
.endif

.include <bsd.port.post.mk>

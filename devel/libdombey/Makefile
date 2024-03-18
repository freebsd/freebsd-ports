PORTNAME=	libdombey
PORTVERSION=	5.56
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.mammothcheese.ca/

MAINTAINER=	jimmy@mammothcheese.ca
COMMENT=	SCGI application server in a library
WWW=		http://mammothcheese.ca/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		ssl
USE_LDCONFIG=	yes
CFLAGS+=	-I${OPENSSLINC}

DESTDIRNAME=	STAGEDIR
MAKE_ARGS=	MANDIR="${STAGEDIR}${PREFIX}/share/man/man3/"

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>

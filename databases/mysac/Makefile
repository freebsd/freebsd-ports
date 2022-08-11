PORTNAME=	mysac
PORTVERSION=	1.1.2
CATEGORIES=	databases
MASTER_SITES=	http://www.arpalert.org/src/ \
		http://xz.cx/downloads/mysac/

MAINTAINER=	jake@xz.cx
COMMENT=	MySQL Simple Asynchronous Client

LICENSE=	LGPL3

USES=		mysql

IGNORE_WITH_MYSQL=	57 80 101m 102m 103m 57p 57w

USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-I${LOCALBASE}/lib

PLIST_FILES=	lib/libmysac.so \
		lib/libmysac.so.0 \
		lib/libmysac-static.a \
		include/mysac.h

pre-build:
	${TOUCH} ${WRKSRC}/make.deps

do-install:
	${INSTALL_LIB} ${WRKSRC}/libmysac.so ${STAGEDIR}${PREFIX}/lib
	${LN} -sf libmysac.so ${STAGEDIR}${PREFIX}/lib/libmysac.so.0
	${INSTALL_DATA} ${WRKSRC}/libmysac-static.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/mysac.h ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>

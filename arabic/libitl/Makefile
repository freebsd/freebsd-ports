# Created by: Samy Al Bahra <samy@kerneled.org>
# $FreeBSD$

PORTNAME=	libitl
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	arabic
MASTER_SITES=	SF/arabeyes/ITL%20Library%20%28${PORTNAME}%29/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	API abstraction to common Islamic calculations

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/lib/itl
MAKE_JOBS_UNSAFE=	yes

post-install:
.for f in libitl.so libitl.so.0
	${RM} ${STAGEDIR}${PREFIX}/lib/itl/$f
	${LN} -s libitl.so.0.0.7 ${STAGEDIR}${PREFIX}/lib/itl/$f
.endfor
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/itl/libitl.so

.include <bsd.port.mk>

# Created by: Olivier Cochard-Labbe <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	libsystem
PORTVERSION=	0.2.0
CATEGORIES=	devel
MASTER_SITES=	http://www.defora.org/os/download/download/4330/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	libSystem-${PORTVERSION}

MAINTAINER=	olivier@cochard.me
COMMENT=	DeforaOS core system library

LICENSE=	GPLv3

USES=		pkgconfig
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
CPPFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
MAKE_ARGS+=	PREFIX=${PREFIX}

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFAULT=	DOCS

post-patch:
	${REINPLACE_CMD} 's|/lib/|/libdata/|g' \
		${WRKSRC}/data/pkgconfig.sh
	${REINPLACE_CMD} 's|CFLAGS=|CFLAGS+=|' \
		${WRKSRC}/src/Makefile
	${REINPLACE_CMD} 's|CPPFLAGS=|CPPFLAGS+=|' \
		${WRKSRC}/src/Makefile
	${REINPLACE_CMD} 's|data doc include|data include|' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} 's|_fail "python.sh"|#_fail "python.sh"|' \
		${WRKSRC}/tests/tests.sh

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/configctl \
		${STAGEDIR}${PREFIX}/lib/libSystem.so.0.0

.include <bsd.port.mk>

PORTNAME=	libinjection
PORTVERSION=	3.10.0
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	SQL / SQLI tokenizer parser analyzer
WWW=		https://github.com/libinjection/libinjection

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../COPYING

USES=		python:build shebangfix

USE_LDCONFIG=	yes
WRKSRC_SUBDIR=	src

PLIST_SUB=	PORTVERSION=${PORTVERSION}

USE_GITHUB=	yes

SHEBANG_GLOB=	*.py

post-patch:
	@${REINPLACE_CMD} -e 's|%%SHLIB_VER%%|${PORTVERSION:R:R}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/libinjection*.h ${STAGEDIR}${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/libinjection.a ${STAGEDIR}${PREFIX}/lib/libinjection.a
	${INSTALL_LIB} ${WRKSRC}/libinjection.so ${STAGEDIR}${PREFIX}/lib/libinjection.so.${PORTVERSION}
	${LN} -s libinjection.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libinjection.so
	${LN} -s libinjection.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libinjection.so.${PORTVERSION:R:R}

.include <bsd.port.mk>

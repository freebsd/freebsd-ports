PORTNAME=	libinjection
PORTVERSION=	3.10.0
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	SQL / SQLI tokenizer parser analyzer
WWW=		https://github.com/libinjection/libinjection

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../COPYING

USES=		python:build shebangfix

WRKSRC_SUBDIR=	src

USE_GITHUB=	yes

SHEBANG_GLOB=	*.py

post-patch:
	@${REINPLACE_CMD} -e 's|%%SHLIB_VER%%|${PORTVERSION:R:R}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/libinjection*.h ${STAGEDIR}${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/libinjection.a ${STAGEDIR}${PREFIX}/lib/libinjection.a
	${INSTALL_LIB} ${WRKSRC}/libinjection.so ${STAGEDIR}${PREFIX}/lib/libinjection.so

.include <bsd.port.mk>

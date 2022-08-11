PORTNAME=	libinjection
PORTVERSION=	3.10.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	SQL / SQLI tokenizer parser analyzer

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python:build shebangfix

USE_GITHUB=	yes

SHEBANG_GLOB=	*.py

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/libinjection*.h ${STAGEDIR}${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/src/libinjection.a ${STAGEDIR}${PREFIX}/lib/libinjection.a
	${INSTALL_LIB} ${WRKSRC}/src/libinjection.so ${STAGEDIR}${PREFIX}/lib/libinjection.so

.include <bsd.port.mk>

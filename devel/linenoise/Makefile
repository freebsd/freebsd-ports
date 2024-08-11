PORTNAME=	linenoise
DISTVERSION=	1.0-34
PORTREVISION=	1
DISTVERSIONSUFFIX=	-g93b2db9
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Small self-contained alternative to readline and libedit
WWW=		https://github.com/antirez/linenoise

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	antirez

PLIST_FILES=	include/linenoise.h \
		lib/liblinenoise.so

do-build:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${CC} \
			${CFLAGS} ${LDFLAGS} \
			-shared \
			-fPIC \
			-Wl,-soname=liblinenoise.so \
			linenoise.c \
			-o liblinenoise.so

do-install:
	${INSTALL_DATA} ${WRKSRC}/linenoise.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/liblinenoise.so ${STAGEDIR}${PREFIX}/lib

do-test:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE} && \
		./linenoise_example

.include <bsd.port.mk>

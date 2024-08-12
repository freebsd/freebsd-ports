PORTNAME=	linenoise
DISTVERSION=	1.0-34
DISTVERSIONSUFFIX=	-g93b2db9
PORTREVISION=	2
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
		lib/liblinenoise.so \
		libdata/pkgconfig/liblinenoise.pc

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
	${SED} \
		-e 's|@prefix@|${PREFIX}|; s|@version@|${PORTVERSION}|' \
		< ${FILESDIR}/liblinenoise.pc.in \
		> ${STAGEDIR}${PREFIX}/libdata/pkgconfig/liblinenoise.pc

do-test:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE} && \
		./linenoise_example

.include <bsd.port.mk>

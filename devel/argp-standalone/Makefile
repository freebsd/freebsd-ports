# Created by: Sergey Matveychuk <sem@ciam.ru>
# $FreeBSD$

PORTNAME=	argp-standalone
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.lysator.liu.se/~nisse/misc/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sem

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Standalone version of arguments parsing functions from GLIBC

USE_CSTD=	gnu89
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	aclocal autoconf automake libtool
AUTOMAKE_ARGS=	-c -a
ACLOCAL_ARGS=	--automake-acdir=${ACLOCAL_DIR} -I ${LOCALBASE}/share/aclocal
USE_LDCONFIG=	yes

PLIST_FILES=	lib/libargp.la lib/libargp.a \
		lib/libargp.so lib/libargp.so.0 \
		include/argp.h

pre-configure:
	@cd ${WRKSRC}; ${SETENV} ${AUTOTOOLS_ENV} ${LIBTOOLIZE} --automake

do-install:
	@cd ${WRKSRC}; \
	${INSTALL_DATA} argp.h ${STAGEDIR}${PREFIX}/include; \
	${INSTALL_DATA} .libs/libargp.la ${STAGEDIR}${PREFIX}/lib; \
	${INSTALL_DATA} .libs/libargp.a ${STAGEDIR}${PREFIX}/lib; \
	${INSTALL_LIB} .libs/libargp.so.0 ${STAGEDIR}${PREFIX}/lib
	@cd ${STAGEDIR}${PREFIX}/lib && ${LN} -sf libargp.so.0 libargp.so

.include <bsd.port.mk>

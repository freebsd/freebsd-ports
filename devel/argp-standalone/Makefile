# New ports collection makefile for:	argp-standalone
# Date created:				1 March 2004
# Whom:					Sergey Matveychuk <sem@ciam.ru>
#
# $FreeBSD$
#

PORTNAME=	argp-standalone
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.lysator.liu.se/~nisse/misc/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sem

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Standalone version of arguments parsing functions from GLIBC

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	aclocal:110 autoconf:262 automake:110 libtool:22
AUTOMAKE_ARGS=	-c -a
ACLOCAL_ARGS=	--acdir=${ACLOCAL_DIR} -I ${LOCALBASE}/share/aclocal
USE_LDCONFIG=	yes

PLIST_FILES=	lib/libargp.la lib/libargp.a \
		lib/libargp.so lib/libargp.so.0 \
		include/argp.h

.include <bsd.port.pre.mk>

pre-configure:
	@cd ${WRKSRC}; ${SETENV} ${AUTOTOOLS_ENV} ${LIBTOOLIZE} --automake

do-install:
	@cd ${WRKSRC}; \
	${INSTALL_DATA} argp.h ${PREFIX}/include; \
	${INSTALL_DATA} .libs/libargp.la ${PREFIX}/lib; \
	${INSTALL_DATA} .libs/libargp.a ${PREFIX}/lib; \
	${INSTALL_PROGRAM} .libs/libargp.so.0 ${PREFIX}/lib
	@cd ${PREFIX}/lib && ${LN} -sf libargp.so.0 libargp.so

.include <bsd.port.post.mk>

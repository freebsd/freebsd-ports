# New ports collection makefile for:	argp-standalone
# Date created:				1 March 2004
# Whom:					Sergey Matveychuk <sem@ciam.ru>
#
# $FreeBSD$
#

PORTNAME=	argp-standalone
PORTVERSION=	1.3
CATEGORIES=	devel
MASTER_SITES=	http://www.lysator.liu.se/~nisse/misc/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sem

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Standalone version of arguments parsing functions from GLIBC

GNU_CONFIGURE=	yes

PLIST_FILES=	lib/libargp.a include/argp.h

do-install:
	@cd ${WRKSRC}; \
	${INSTALL_DATA} libargp.a ${PREFIX}/lib; \
	${INSTALL_DATA} argp.h ${PREFIX}/include

.include <bsd.port.mk>

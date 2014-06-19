# Created by: jkoshy
# $FreeBSD$

PORTNAME=	siod
PORTVERSION=	3.4
CATEGORIES=	lang scheme
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR= jkoshy
DISTNAME=	siod
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small footprint implementation of the Scheme programming language

USE_LDCONFIG=	yes

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
ALL_TARGET=	freebsd
MAKE_ENV=	LD_LIBRARY_PATH=.
MAKE_JOBS_UNSAFE=	yes

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/siod

.include <bsd.port.mk>

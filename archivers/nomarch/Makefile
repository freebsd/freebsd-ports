# ex:ts=8
# New ports collection makefile for:	nomarch
# Date created:			Nov 5, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	nomarch
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/compress

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extracts files from the old `.arc' archive format

USE_GETOPT_LONG=yes
MAKE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

MAN1=	nomarch.1
PLIST_FILES=	bin/nomarch

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nomarch ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nomarch.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>

# ex:ts=8
# Ports collection makefile for:	exiftags
# Date created:			Sep 13, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	exiftags
PORTVERSION=	0.94
CATEGORIES=	graphics
MASTER_SITES=	http://johnst.org/sw/exiftags/

MAINTAINER=	ports@FreeBSD.org

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" PREFIX="${PREIFX}"

MAN1=	exiftags.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/exiftags ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/exiftags.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>

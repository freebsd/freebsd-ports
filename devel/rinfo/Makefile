# New ports collection makefile for:    rinfo
# Date created:         23th March 1998
# Whom:                 Mark Chapman <markc@ctgi.net>
#
# $FreeBSD$
#

PORTNAME=	rinfo
PORTVERSION=	1.2
CATEGORIES=	devel
MASTER_SITES=	ftp://www.ctgi.net/pub/ctgi/

MAINTAINER=	markc@ctgi.net
COMMENT=	List status of files checked out of RCS repositories

PLIST_FILES=	bin/rinfo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rinfo ${PREFIX}/bin/rinfo

.include <bsd.port.mk>

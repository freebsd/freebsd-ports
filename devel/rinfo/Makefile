# New ports collection makefile for:    rinfo
# Date created:         23th March 1998
# Whom:                 Mark Chapman <markc@ctgi.net>
#
# $FreeBSD$
#

PORTNAME=	rinfo
PORTVERSION=	1.2
CATEGORIES=	devel
MASTER_SITES=	ftp://www.ctgi.net/pub/ctgi/ \
		http://www.freebsdbrasil.com.br/~jmelo/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	List status of files checked out of RCS repositories

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

PLIST_FILES=	bin/rinfo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rinfo ${PREFIX}/bin/rinfo

.include <bsd.port.mk>

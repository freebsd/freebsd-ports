# New ports collection makefile for:   db-netbsd
# Date created:        1 January 2004
# Whom:                Edwin Groothuis (edwin@mavetju.org)
#
# $FreeBSD$
#

PORTNAME=	db
PORTVERSION=	1.11
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.mavetju.org/download/

MAINTAINER=	edwin@mavetju.org
COMMENT=	Manipulate db(3)'s btree(3) and hash(3) databases - NetBSD port

MAN1=		db.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/db

MAKE_ENV=	BINDIR=${PREFIX}/bin SHAREDIR=${PREFIX}

.include <bsd.port.mk>

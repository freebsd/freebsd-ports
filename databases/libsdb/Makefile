# ex:ts=8
# New ports collection makefile for:	libsdb
# Date created:			Jul 2, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libsdb
PORTVERSION=	0.6.1
CATEGORIES=	databases
MASTER_SITES=	ftp://siag.nu/pub/libsdb/ \
		http://siag.nu/pub/libsdb/
DISTNAME=	sdb-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple database library

INSTALLS_SHLIB=	yes
HAS_CONFIGURE=	yes
MAKE_ARGS=	PREFIX="${PREFIX}" CC="${CC}" CFLAGS="${CFLAGS}"

MAN3=		sdb.3 sdb_init.3 sdb_open.3 sdb_close.3 sdb_query.3
MAN8=		sdbd.8

.include <bsd.port.mk>

# ex:ts=8
# Ports collection makefile for:	tinycdb
# Date created:			Oct 17, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tinycdb
PORTVERSION=	0.73
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.corpit.ru/pub/tinycdb/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Analogous to cdb, but faster

USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" prefix="${PREFIX}"

MAN1=	cdb.1
MAN3=	cdb.3
MAN5=	cdb.5

.include <bsd.port.mk>

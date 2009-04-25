# ex:ts=8
# Ports collection makefile for:	tinycdb
# Date created:			Oct 17, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tinycdb
PORTVERSION=	0.77
CATEGORIES=	databases
MASTER_SITES=	http://www.corpit.ru/mjt/tinycdb/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	Analogous to cdb, but faster

USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" prefix="${PREFIX}"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		cdb.1
MAN3=		cdb.3
MAN5=		cdb.5

PLIST_FILES=	bin/cdb include/cdb.h lib/libcdb.a

.include <bsd.port.mk>

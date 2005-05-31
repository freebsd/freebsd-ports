# ex:ts=8
# New ports collection makefile for:	libsdb
# Date created:			Jul 2, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libsdb
PORTVERSION=	0.5.5
CATEGORIES=	databases
MASTER_SITES=	ftp://siag.nu/pub/libsdb/ \
		http://siag.nu/pub/libsdb/
DISTNAME=	sdb-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple database library

USE_GNOME=	gnometarget lthack
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes

MAN3=		sdb.3 sdb_init.3 sdb_open.3 sdb_close.3 sdb_query.3
MAN8=		sdbd.8

post-patch:
	@${REINPLACE_CMD} -e \
		's|= -lsdb|= $$(top_builddir)/libsdb.la|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>

# New ports collection makefile for:	gmysql
# Date created:		Sun Nov 15 22:07:12 CET 1998
# Whom:			Dirk Froemberg <ibex@physik.TU-Berlin.DE>
#
# $FreeBSD$
#

PORTNAME=	gmysql
PORTVERSION=	0.3.4
PORTREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	http://www.physik.TU-Berlin.DE/~ibex/ports/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ frontend for mysql

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client

USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-mysql=${PREFIX}

MAN1=		gmysql.1
PLIST_FILES=	bin/gmysql

.include <bsd.port.mk>

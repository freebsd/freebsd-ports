# New ports collection makefile for:	gmysql
# Version required:	0.3.2
# Date created:		Sun Nov 15 22:07:12 CET 1998
# Whom:			Dirk Froemberg <ibex@physik.TU-Berlin.DE>
#
# $Id: Makefile,v 1.12 1999/05/29 03:55:32 steve Exp $
#

DISTNAME=	gmysql-0.3.2
CATEGORIES=	databases
MASTER_SITES=	http://www.loth.demon.co.uk/gmysql/ \
		http://www.physik.TU-Berlin.DE/~ibex/ports/distfiles/

MAINTAINER=	dirk@FreeBSD.ORG

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		mysqlclient.6:${PORTSDIR}/databases/mysql322-client

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-mysql=${PREFIX}
CONFIGURE_ENV=	GTK_CONFIG=${GTK_CONFIG}
FETCH_BEFORE_ARGS=	-b

.include <bsd.port.mk>

# New ports collection makefile for:	gmysql
# Version required:	0.3.1
# Date created:		Sun Nov 15 22:07:12 CET 1998
# Whom:			Dirk Froemberg <ibex@physik.TU-Berlin.DE>
#
# $Id: Makefile,v 1.4 1999/01/14 21:22:24 dirk Exp $
#

DISTNAME=	gmysql-0.3.1
CATEGORIES=	databases
MASTER_SITES=	http://www.loth.demon.co.uk/gmysql/ \
		http://www.physik.TU-Berlin.DE/~ibex/ports/distfiles/

MAINTAINER=	dirk@FreeBSD.ORG

LIB_DEPENDS=	gtk11.1:${PORTSDIR}/x11-toolkits/gtk11 \
		mysqlclient.5:${PORTSDIR}/databases/mysql322

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-mysql=${PREFIX}
CONFIGURE_ENV=	GTK_CONFIG=${X11BASE}/bin/gtk11-config
FETCH_BEFORE_ARGS=	-b

.include <bsd.port.mk>

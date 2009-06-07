# New ports collection makefile for:  munger
# Date created:                       Thu, 03 Jul 2003 20:05:06 EDT
# Whom:                               James Bailie <jimmy@mammothcheese.ca>
#
# $FreeBSD$
#

PORTNAME=	munger
PORTVERSION=	4.169
CATEGORIES=	lang
MASTER_SITES=	http://www.mammothcheese.ca/

MAINTAINER=	jimmy@mammothcheese.ca
COMMENT=	Static lisp interpreter with text processing abilities

DATADIR=	${PREFIX}/share/${PORTNAME}-${PORTVERSION}

MAN1=		munger.1
MANCOMPRESSED=	yes

OPTIONS=	SQL  "include SQLite interface"  on

USE_LDCONFIG=	yes

.if !defined(WITHOUT_SQL)
USE_SQLITE=	3
MAKE_ARGS+=	-DWITH_SQL
.endif

.include <bsd.port.mk>

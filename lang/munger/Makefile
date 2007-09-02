# New ports collection makefile for:  munger
# Date created:                       Thu, 03 Jul 2003 20:05:06 EDT
# Whom:                               James Bailie <jimmy@mammothcheese.ca>
#
# $FreeBSD$
#

PORTNAME=	munger
PORTVERSION=	4.138
CATEGORIES=	lang
MASTER_SITES=	http://www.mammothcheese.ca/

MAINTAINER=	jimmy@mammothcheese.ca
COMMENT=	Static lisp interpreter with text processing abilities

DATADIR=	${PREFIX}/share/${PORTNAME}-${PORTVERSION}

MAN1=		munger.1
MANCOMPRESSED=	yes

OPTIONS=	SQL  "include SQLite interface"  on \
		DKNS "install Dickens text editor" off

USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_SQL)
USE_SQLITE=	3
MAKE_ARGS+=	-DWITH_SQL
.endif

.if defined(WITH_DKNS)
MAKE_ARGS+=	-DWITH_DKNS
MAN1+=		dkns.1
PLIST_SUB+=	DKNS_BIN="bin/dkns"
.else
PLIST_SUB+=	DKNS_BIN="${DATADIR:S,^${PREFIX}/,,}/dkns.munger"
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:  munger
# Date created:                       Thu, 03 Jul 2003 20:05:06 EDT
# Whom:                               James Bailie <jimmy@jamesbailie.com>
#
# $FreeBSD$
#

PORTNAME=	munger
PORTVERSION=	4.55
CATEGORIES=	lang
MASTER_SITES=	http://www.jamesbailie.com/

MAINTAINER=	jimmy@jamesbailie.com
COMMENT=	Static lisp interpreter with text processing abilities

RUN_DEPENDS=	nc:${PORTSDIR}/net/netcat

MAN1=		munger.1
MANCOMPRESSED=	yes
PLIST_SUB=	MUNGER_VERSION=${PORTVERSION}

OPTIONS=	FCGI "include FastCGI interface" on \
		SQL  "include SQLite interface"  on \
		TERM "include character-I/O functions" on

.include <bsd.port.pre.mk>

.if defined(WITH_SQL)
LIB_DEPENDS+=	sqlite3.8:${PORTSDIR}/databases/sqlite3
MAKE_ARGS+=	-DWITH_SQL
.endif

.if defined(WITH_FCGI)
LIB_DEPENDS+=	fcgi.0:${PORTSDIR}/www/fcgi
MAKE_ARGS+=	-DWITH_FCGI
.endif

.if defined(WITH_TERM)
MAKE_ARGS+=	-DWITH_TERM
.endif

post-build:
.if defined(WITH_FCGI)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>

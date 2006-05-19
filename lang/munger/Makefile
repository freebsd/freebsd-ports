# New ports collection makefile for:  munger
# Date created:                       Thu, 03 Jul 2003 20:05:06 EDT
# Whom:                               James Bailie <jimmy@jamesbailie.com>
#
# $FreeBSD$
#

PORTNAME=	munger
PORTVERSION=	4.103
CATEGORIES=	lang
MASTER_SITES=	http://www.jamesbailie.com/

MAINTAINER=	jimmy@jamesbailie.com
COMMENT=	Static lisp interpreter with text processing abilities

DATADIR=	${PREFIX}/share/${PORTNAME}-${PORTVERSION}

MAN1=		munger.1
MANCOMPRESSED=	yes

OPTIONS=	FCGI "include FastCGI interface" on \
		SQL  "include SQLite interface"  on \
		TERM "include character-I/O functions" on \
		BN   "include bignum support" off \
		DKNS "install Dickens text editor" off

INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_SQL)
USE_SQLITE=	3
MAKE_ARGS+=	-DWITH_SQL
.endif

.if !defined(WITHOUT_FCGI)
LIB_DEPENDS+=	fcgi.0:${PORTSDIR}/www/fcgi
MAKE_ARGS+=	-DWITH_FCGI
.endif

.if !defined(WITHOUT_TERM)
MAKE_ARGS+=	-DWITH_TERM
.endif

.if defined(WITH_BN)
MAKE_ARGS+=	-DWITH_BN
.endif

.if defined(WITH_DKNS)
MAKE_ARGS+=	-DWITH_DKNS
MAN1+=		dkns.1
PLIST_SUB+=	DKNS_BIN="bin/dkns"
.else
PLIST_SUB+=	DKNS_BIN="${DATADIR:S,^${PREFIX}/,,}/dkns.munger"
.endif

post-build:
.if !defined(WITHOUT_FCGI)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>

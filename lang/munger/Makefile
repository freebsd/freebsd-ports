# New ports collection makefile for:  munger
# Date created:                       Thu, 03 Jul 2003 20:05:06 EDT
# Whom:                               James Bailie <jimmy@jamesbailie.com>
#
# $FreeBSD$
#

PORTNAME=	munger
PORTVERSION=	4.44
CATEGORIES=	lang
MASTER_SITES=	http://www.jamesbailie.com/

MAINTAINER=	jimmy@jamesbailie.com
COMMENT=	Static lisp interpreter with text processing abilities

PLIST_SUB=	MUNGER_VERSION=${PORTVERSION}

LIB_DEPENDS=	expat.5:${PORTSDIR}/textproc/expat2

MAN1=		munger.1 httpf.1 xml2munger.1
MANCOMPRESSED=	yes

.if !defined(PACKAGE_BUILDING)
IS_INTERACTIVE=	yes
OPTIONS=	FCGI "include FastCGI interface" on \
		SQL  "include SQLite interface"  on \
		TERM "include character-I/O functions" on
.else
WITH_SQL=	yes
WITH_FCGI=	yes
WITH_TERM=	yes
.endif

# Prevents SQLite from obnoxiously installing Tcl/Tk merely to build its docs.

NOPORTDOCS=	yes

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

# New ports collection makefile for:	munger
# Date created:				Thu, 03 Jul 2003 20:05:06 EDT
# Whom:					James Bailie <jimmy@jamesbailie.com>
#
# $FreeBSD$
#

PORTNAME=	munger
PORTVERSION=	4.38
CATEGORIES=	lang
MASTER_SITES=	http://jamesbailie.com/

MAINTAINER=	jimmy@jamesbailie.com
COMMENT=	Static LISP interpreter with text processing abilities

LIB_DEPENDS=	expat.5:${PORTSDIR}/textproc/expat2

.if defined(WITH_SQL)
LIB_DEPENDS+=	sqlite.2:${PORTSDIR}/databases/sqlite
.endif

.if defined(WITH_FCGI)
LIB_DEPENDS+=	fcgi.0:${PORTSDIR}/www/fcgi
.endif

MAN1=		munger.1 httpf.1 xml2munger.1
MANCOMPRESSED=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"

.include <bsd.port.mk>

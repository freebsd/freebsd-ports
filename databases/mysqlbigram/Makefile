# New ports collection makefile for:	mysqlbigram
# Date created:		2007-07-25
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	mysqlbigram
PORTVERSION=	1.0.1
CATEGORIES=	databases
MASTER_SITES=	http://mysqlbigram.googlepages.com/
DISTFILES=	bi_gram-src-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	gslin@gslin.org
COMMENT=	Simple N-Gram (bi-gram) FULLTEXT parser plugin for MySQL 5.1+

CFLAGS+=	-I"${LOCALBASE}/include" -I"${LOCALBASE}/include/mysql"
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
GNU_CONFIGURE=	yes
IGNORE_WITH_MYSQL=	323 40 41 50
LDFLAGS+=	-L${LOCALBASE}/lib
USE_MYSQL=	yes
WANT_MYSQL_VER?=	51
WRKSRC=		${WRKDIR}/bi_gram

.include <bsd.port.mk>

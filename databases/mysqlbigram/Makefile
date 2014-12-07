# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	mysqlbigram
PORTVERSION=	1.0.1
CATEGORIES=	databases
MASTER_SITES=	http://mysqlbigram.googlepages.com/
DISTNAME=	bi_gram-src-${PORTVERSION}

MAINTAINER=	gslin@gslin.org
COMMENT=	Simple n-gram (bi-gram) fulltext parser plugin for MySQL

LICENSE=	LGPL21

GNU_CONFIGURE=	yes
USE_MYSQL=	yes
WRKSRC=		${WRKDIR}/bi_gram

PLIST_FILES=	lib/mysql/bi_gramlib.la \
		lib/mysql/bi_gramlib.so \
		lib/mysql/bi_gramlib.so.0

post-patch:
	@${REINPLACE_CMD} -e 's,bool ,my_&,' ${WRKSRC}/bi_gram_plugin.c

.include <bsd.port.mk>

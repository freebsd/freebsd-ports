# Created by: Qing Feng <qingfeng@douban.com>
# $FreeBSD$

PORTNAME=	beansdb
PORTVERSION=	0.5.3
CATEGORIES=	databases
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	qingfeng@douban.com
COMMENT=	Yet another distributed key-value storage system from Douban Inc

GNU_CONFIGURE=	yes
USE_CSTD=	gnu89
CFLAGS+=	${PTHREAD_LIBS}

PLIST_FILES=	bin/beansdb \
		man/man1/beansdb.1.gz

.include <bsd.port.mk>

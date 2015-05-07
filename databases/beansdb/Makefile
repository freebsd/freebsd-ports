# Created by: Qing Feng <qingfeng@douban.com>
# $FreeBSD$

PORTNAME=	beansdb
PORTVERSION=	0.5.3
CATEGORIES=	databases
MASTER_SITES=	GOOGLE_CODE \
		http://mirror.amdmi3.ru/googlecode/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet another distributed key-value storage system from Douban Inc

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
USE_CSTD=	gnu89
LDFLAGS+=	-lpthread

PLIST_FILES=	bin/beansdb \
		man/man1/beansdb.1.gz

.include <bsd.port.mk>

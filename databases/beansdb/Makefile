PORTNAME=	beansdb
PORTVERSION=	0.7.1.4
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet another distributed key-value storage system from Douban Inc
WWW=		https://github.com/douban/beansdb

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	douban

USES=		autoreconf
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/beansdb share/man/man1/beansdb.1.gz

.include <bsd.port.mk>

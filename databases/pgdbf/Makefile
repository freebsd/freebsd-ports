PORTNAME=	pgdbf
PORTVERSION=	0.6.2
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	SF

MAINTAINER=	kirk@strauser.com
COMMENT=	Convert XBase / FoxPro tables to PostgreSQL
WWW=		https://pgdbf.sourceforge.net/

LICENSE=	GPLv3

USES=		gmake tar:xz
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/pgdbf \
		%%DOCSDIR%%/README \
		share/man/man1/pgdbf.1.gz

.include <bsd.port.mk>

# Created by: Sevan Janiyan <venture37@geeklan.co.uk>
# $FreeBSD$

PORTNAME=	hashtypes
PORTVERSION=	0.1.1
PORTREVISION=	2
CATEGORIES=	databases security
MASTER_SITES=	http://api.pgxn.org/dist/hashtypes/${PORTVERSION}/ \
		http://oss-files.dreamindustries.co/mirror/

MAINTAINER=	oss-contrib@dreamindustries.co
COMMENT=	Hash data types for PostgreSQL

USES=		gmake pgsql zip
LLD_UNSAFE=	yes

MAKE_ARGS=	USE_PGXS=1 MODULEDIR=extension
MODULEDIR=	${PREFIX}/share/postgresql/extension

post-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.control ${STAGEDIR}${MODULEDIR}

.include <bsd.port.mk>

# Created by: alp@sfedu.ru
# $FreeBSD$

PORTNAME=	postgresql-repmgr
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.repmgr.org/download/
DISTNAME=	repmgr-${PORTVERSION}

MAINTAINER=	5u623l20@gmail.com
COMMENT=	PostgreSQL replication manager

LICENSE=	GPLv3

RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync

USES+=		gmake pgsql:9.0+
WANT_PGSQL=	server
MAKE_ENV=	USE_PGXS=1

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README.*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/repmgr ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/repmgrd ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rst ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/repmgr.conf.sample ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/repmgr.sql ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>

# Created by: alp@sfedu.ru
# $FreeBSD$

PORTNAME=	postgresql-repmgr
PORTVERSION=	1.2.0
CATEGORIES=	databases
MASTER_SITES=	http://www.repmgr.org/download/
DISTNAME=	repmgr-${PORTVERSION}

MAINTAINER=	alp@sfedu.ru
COMMENT=	PostgreSQL replication manager

LICENSE=	GPLv3

RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync

USES=	gmake
USE_PGSQL=	yes
WANT_PGSQL_VER=	90+
MAKE_ENV=	USE_PGXS=1

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README.*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/repmgr ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/repmgrd ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rst ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/repmgr.conf ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/repmgr.sql ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>

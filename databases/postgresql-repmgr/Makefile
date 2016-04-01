# Created by: alp@sfedu.ru
# $FreeBSD$

PORTNAME=	postgresql-repmgr
PORTVERSION=	2.0.2
CATEGORIES=	databases
MASTER_SITES=	http://www.repmgr.org/download/
DISTNAME=	repmgr-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	PostgreSQL replication manager

LICENSE=	GPLv3

RUN_DEPENDS=	rsync:net/rsync

USES+=		gmake pgsql:9.0+
USE_RC_SUBR=	repmgrd
WANT_PGSQL=	server
MAKE_ENV=	USE_PGXS=1

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/repmgr ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/repmgrd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/repmgr.conf.sample ${STAGEDIR}${PREFIX}/etc
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rst ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/repmgr.sql ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sql/repmgr_funcs.sql ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sql/uninstall_repmgr_funcs.sql ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/postgresql
	${INSTALL_LIB} ${WRKSRC}/sql/repmgr_funcs.so ${STAGEDIR}${PREFIX}/lib/postgresql

.include <bsd.port.mk>

# New ports collection makefile for:  	repmgr
# Date created:                		January 15, 2011
# Whom:					alp@sfedu.ru
# $FreeBSD$

PORTNAME=		postgresql-repmgr
PORTVERSION=		1.0.0
CATEGORIES=		databases
MASTER_SITES=		http://projects.2ndquadrant.it/sites/default/files/
DISTNAME=		repmgr-${PORTVERSION}

MAINTAINER=		alp@sfedu.ru
COMMENT=		PostgreSQL replication manager

BUILD_DEPENDS+=		postgresql-server>=9.0:${PORTSDIR}/databases/postgresql90-server
RUN_DEPENDS=		${BUILD_DEPNDS} \
			rsync:${PORTSDIR}/net/rsync

USE_GMAKE=		yes
MAKE_ENV=		USE_PGXS=1

PORTDOCS=		README.*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/repmgr ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/repmgrd ${PREFIX}/sbin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rst    ${DOCSDIR}
.endif
.if !defined(NOPORTDATA)
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/repmgr.conf   ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/repmgr.sql    ${DATADIR}
.endif

.include <bsd.port.mk>

# Created by: alp@sfedu.ru
# $FreeBSD$

PORTNAME=	postgresql-repmgr
PORTVERSION=	4.2.0
CATEGORIES=	databases
MASTER_SITES=	http://www.repmgr.org/download/
DISTNAME=	repmgr-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	PostgreSQL replication manager

LICENSE=	GPLv3

RUN_DEPENDS=	rsync:net/rsync

USES+=		gettext gmake pgsql:9.3+

GNU_CONFIGURE=	yes
LLD_UNSAFE=	yes
USE_RC_SUBR=	repmgrd
WANT_PGSQL=	server
MAKE_ENV=	USE_PGXS=1
LIBS=		-L${LOCALBASE}/lib -lintl

OPTIONS_DEFINE=	DOCS

PORTDOCS=	CONTRIBUTING.md COPYRIGHT CREDITS FAQ.md HISTORY LICENSE PACKAGES.md \
	       	README.md

post-install:
	${INSTALL_DATA} ${WRKSRC}/repmgr.conf.sample ${STAGEDIR}${PREFIX}/etc
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/repmgr
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/repmgrd
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/repmgr.so

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

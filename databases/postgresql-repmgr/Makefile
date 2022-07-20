PORTNAME=	postgresql-repmgr
PORTVERSION=	5.3.2
CATEGORIES=	databases
MASTER_SITES=	http://www.repmgr.org/download/
DISTNAME=	repmgr-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	PostgreSQL replication manager

LICENSE=	GPLv3

RUN_DEPENDS=	rsync:net/rsync

USES=		gettext gmake pgsql
WANT_PGSQL=	server
USE_RC_SUBR=	repmgrd

GNU_CONFIGURE=	yes

MAKE_ENV=	USE_PGXS=1

LIBS=		-L${LOCALBASE}/lib -lintl

LLD_UNSAFE=	yes

PORTDOCS=	CONTRIBUTING.md COPYRIGHT CREDITS FAQ.md HISTORY LICENSE \
		PACKAGES.md README.md

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${DOCSDIR}
.endfor

post-install:
	${INSTALL_DATA} ${WRKSRC}/repmgr.conf.sample ${STAGEDIR}${PREFIX}/etc
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/repmgr
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/repmgrd
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/repmgr.so

.include <bsd.port.mk>

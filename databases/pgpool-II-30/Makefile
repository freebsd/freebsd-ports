# Created by: Choe, Cheng-Dae <whitekid@gmail.com>
# $FreeBSD$

PORTNAME=	pgpool-II
PORTVERSION=	3.0.4
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/3076/
PKGNAMESUFFIX=	30

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Connection pool server for PostgreSQL

LICENSE=	MIT

DEPRECATED=	Deprecated by upstream; use database/pgpool instead
EXPIRATION_DATE=	2017-06-15

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gmake pgsql:9.2 libtool
USE_LDCONFIG=	yes

CONFLICTS=	pgpool-3.* pgpool-II-3.* pgpool-II-22-* pgpool-II-23-*
USE_RC_SUBR=	pgpool

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README README.euc_jp
PORTDOCS+=	TODO
PORTDOCShtml=	pgpool-en.html pgpool-ja.html pgpool.css
PORTDOCShtml+=	tutorial-en.html tutorial-ja.html

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's| pg_config| ${LOCALBASE}/bin/pg_config|g' \
	${WRKSRC}/sql/pgpool-recovery/Makefile

post-build:
	@cd ${WRKSRC}/sql/pgpool-recovery && ${SETENV} ${MAKE_ENV} ${MAKE_CMD}

post-install:
	echo "--- ==="
	-cat `pg_config --pgxs`
	echo "--- ==="
	@cd ${WRKSRC}/sql/pgpool-recovery && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} DESTDIR=${STAGEDIR} ${INSTALL_TARGET}
	${INSTALL_DATA} ${WRKSRC}/sample/dist_def_pgbench.sql ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sample/replicate_def_pgbench.sql ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in pgpool_recovery pgpool_recovery_pitr pgpool_remote_start
	${INSTALL_SCRIPT} ${WRKSRC}/sample/${f}  ${STAGEDIR}${EXAMPLESDIR}
.endfor
	@${MKDIR}  ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/$f  ${STAGEDIR}${DOCSDIR}
.endfor
.for f in ${PORTDOCShtml}
	${INSTALL_MAN} ${WRKSRC}/doc/$f  ${STAGEDIR}${DOCSDIR}
.endfor
PORTDOCS+=	${PORTDOCShtml}

.include <bsd.port.mk>

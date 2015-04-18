# Created by: Choe, Cheng-Dae <whitekid@gmail.com>
# $FreeBSD$

PORTNAME=	pgpool-II
PORTVERSION=	2.2.6
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/2478/
PKGNAMESUFFIX=	22

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Connection pool server for PostgreSQL

LICENSE=	MIT

USES=		gmake pgsql libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFLICTS=	pgpool-3.* pgpool-II-3.* pgpool-II-23-* pgpool-II-30-* 
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

pre-install:
	${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${EXAMPLESDIR}

post-install:
	@cd ${WRKSRC}/sql/pgpool-recovery && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} DESTDIR=${STAGEDIR} ${INSTALL_TARGET}
	${INSTALL_DATA} ${WRKSRC}/sample/dist_def_pgbench.sql ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sample/replicate_def_pgbench.sql ${STAGEDIR}${DATADIR}
.for f in pgpool_recovery pgpool_recovery_pitr pgpool_remote_start
	${INSTALL_SCRIPT} ${WRKSRC}/sample/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/$f ${STAGEDIR}${DOCSDIR}
.endfor
.for f in ${PORTDOCShtml}
	${INSTALL_MAN} ${WRKSRC}/doc/$f ${STAGEDIR}${DOCSDIR}
.endfor
PORTDOCS+=	${PORTDOCShtml}

.include <bsd.port.mk>

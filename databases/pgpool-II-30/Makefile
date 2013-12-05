# Created by: Choe, Cheng-Dae <whitekid@gmail.com>
# $FreeBSD$

PORTNAME=	pgpool-II
PORTVERSION=	3.0.4
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/3076/
PKGNAMESUFFIX=	30

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	A connection pool server for PostgreSQL

LICENSE=	BSD

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_PGSQL=	yes
USE_LDCONFIG=	yes

CONFLICTS=	pgpool-3.* pgpool-II-3.* pgpool-II-22-* pgpool-II-23-* 
USE_RC_SUBR=	pgpool

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README README.euc_jp
PORTDOCS+=	TODO
PORTDOCShtml=	pgpool-en.html pgpool-ja.html pgpool.css
PORTDOCShtml+=	tutorial-en.html tutorial-ja.html

MAN8=		pgpool.8

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
	${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's| pg_config| ${LOCALBASE}/bin/pg_config|g' \
	${WRKSRC}/sql/pgpool-recovery/Makefile

post-build:
	@cd ${WRKSRC}/sql/pgpool-recovery && ${GMAKE}

post-install:
	@cd ${WRKSRC}/sql/pgpool-recovery && ${GMAKE} ${INSTALL_TARGET}
	${INSTALL_DATA} ${WRKSRC}/sample/dist_def_pgbench.sql ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sample/replicate_def_pgbench.sql ${DATADIR}
	${MKDIR} ${DATADIR} ${EXAMPLESDIR}
.for f in pgpool_recovery pgpool_recovery_pitr pgpool_remote_start
	${INSTALL_SCRIPT} ${WRKSRC}/sample/${f} ${EXAMPLESDIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/$f ${DOCSDIR}
.endfor
.for f in ${PORTDOCShtml}
	${INSTALL_MAN} ${WRKSRC}/doc/$f ${DOCSDIR}
.endfor
PORTDOCS+=	${PORTDOCShtml}
.endif

.include <bsd.port.mk>

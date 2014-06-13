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

USES=		gmake libtool
GNU_CONFIGURE=	yes
USE_PGSQL=	yes
USE_LDCONFIG=	yes

CONFLICTS=	pgpool-3.* pgpool-II-3.* pgpool-II-23-* pgpool-II-30-* 
USE_RC_SUBR=	pgpool

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README README.euc_jp
PORTDOCS+=	TODO
PORTDOCShtml=	pgpool-en.html pgpool-ja.html pgpool.css
PORTDOCShtml+=	tutorial-en.html tutorial-ja.html

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
	${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's| pg_config| ${LOCALBASE}/bin/pg_config|g' \
	${WRKSRC}/sql/pgpool-recovery/Makefile

post-build:
	@cd ${WRKSRC}/sql/pgpool-recovery && ${GMAKE}

pre-install:
	${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${EXAMPLESDIR}

post-install:
	@cd ${WRKSRC}/sql/pgpool-recovery && ${GMAKE} DESTDIR=${STAGEDIR} ${INSTALL_TARGET}
	${INSTALL_DATA} ${WRKSRC}/sample/dist_def_pgbench.sql ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sample/replicate_def_pgbench.sql ${STAGEDIR}${DATADIR}
.for f in pgpool_recovery pgpool_recovery_pitr pgpool_remote_start
	${INSTALL_SCRIPT} ${WRKSRC}/sample/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/$f ${STAGEDIR}${DOCSDIR}
.endfor
.for f in ${PORTDOCShtml}
	${INSTALL_MAN} ${WRKSRC}/doc/$f ${STAGEDIR}${DOCSDIR}
.endfor
PORTDOCS+=	${PORTDOCShtml}
.endif

.include <bsd.port.mk>

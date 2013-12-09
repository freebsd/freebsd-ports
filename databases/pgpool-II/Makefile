# Created by: Choe, Cheng-Dae <whitekid@gmail.com>
# $FreeBSD$

PORTNAME=	pgpool-II
PORTVERSION=	3.1.6
CATEGORIES=	databases
MASTER_SITES=	LOCAL/kuriyama \
		http://www.pgpool.net/mediawiki/images/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	A connection pool server for PostgreSQL

LICENSE=	BSD

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_PGSQL=	yes
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
CONFIGURE_ARGS=	--with-openssl

CONFLICTS=	pgpool-3.* pgpool-II-22-* pgpool-II-23-* pgpool-II-23-* 
USE_RC_SUBR=	pgpool

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README README.euc_jp
PORTDOCS+=	TODO
PORTDOCShtml=	pgpool-en.html pgpool-ja.html pgpool.css
PORTDOCShtml+=	tutorial-en.html tutorial-ja.html

MAN8=		pgpool.8

OPTIONS_DEFINE+=SSL
SSL_DESC=	Build with OpenSSL support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--with-openssl
.endif

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/include/postgresql/server/replication/walreceiver.h)
FUNCTIONS=	pgpool-recovery pgpool-regclass pgpool-walrecrunning
PLIST_SUB=	PGSQL9=""
.else
FUNCTIONS=	pgpool-recovery pgpool-regclass
PLIST_SUB=	PGSQL9="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
	${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's| pg_config| ${LOCALBASE}/bin/pg_config|g' \
	${WRKSRC}/sql/pgpool-recovery/Makefile

post-build:
.for f in ${FUNCTIONS}
	@cd ${WRKSRC}/sql/${f} && ${GMAKE}
.endfor

post-install:
.for f in ${FUNCTIONS}
	@cd ${WRKSRC}/sql/${f} && ${GMAKE} ${INSTALL_TARGET}
.endfor
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

.include <bsd.port.post.mk>

# Created by: Choe, Cheng-Dae <whitekid@gmail.com>
# $FreeBSD$

PORTNAME=	pgpool-II
PORTVERSION=	3.1.6
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	LOCAL/kuriyama \
		http://www.pgpool.net/mediawiki/images/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Connection pool server for PostgreSQL

LICENSE=	MIT

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gmake pgsql:9.2 libtool
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
CONFIGURE_ARGS=	--with-openssl

CONFLICTS=	pgpool-3.* pgpool-II-22-* pgpool-II-23-* pgpool-II-23-*
USE_RC_SUBR=	pgpool

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README README.euc_jp
PORTDOCS+=	TODO
PORTDOCShtml=	pgpool-en.html pgpool-ja.html pgpool.css
PORTDOCShtml+=	tutorial-en.html tutorial-ja.html

OPTIONS_DEFINE+=	DOCS SSL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--with-openssl
.endif

.if exists(${LOCALBASE}/include/postgresql/server/replication/walreceiver.h)
FUNCTIONS=	pgpool-recovery pgpool-regclass pgpool-walrecrunning
PLIST_SUB=	PGSQL9=""
.else
FUNCTIONS=	pgpool-recovery pgpool-regclass
PLIST_SUB=	PGSQL9="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| pg_config| ${LOCALBASE}/bin/pg_config|g' \
	${WRKSRC}/sql/pgpool-recovery/Makefile

post-build:
.for f in ${FUNCTIONS}
	@cd ${WRKSRC}/sql/${f} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD}
.endfor

post-install:
.for f in ${FUNCTIONS}
	@cd ${WRKSRC}/sql/${f} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} DESTDIR=${STAGEDIR}  ${INSTALL_TARGET}
.endfor
	${INSTALL_DATA} ${WRKSRC}/sample/dist_def_pgbench.sql ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sample/replicate_def_pgbench.sql ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in pgpool_recovery pgpool_recovery_pitr pgpool_remote_start
	${INSTALL_SCRIPT} ${WRKSRC}/sample/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor
.if ${PORT_OPTIONS:MDOCS}
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

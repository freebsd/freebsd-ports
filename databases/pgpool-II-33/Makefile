# $FreeBSD$

PORTNAME=	pgpool-II
PORTVERSION=	3.3.7
CATEGORIES=	databases
MASTER_SITES=	http://www.pgpool.net/mediawiki/images/
PKGNAMESUFFIX=	33

MAINTAINER=	michelle@sorbs.net
COMMENT=	Connection pool server for PostgreSQL

LICENSE=	MIT

RUN_DEPENDS=	rsync:net/rsync

USES=		gmake libtool perl5 pgsql
WANT_PGSQL=	client
USE_PERL5=	run
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_ENV=	INSTALL_STRIP_FLAG=${STRIP}

CONFLICTS=	pgpool-3.* pgpool-II-22-2.* pgpool-II-23-2.* pgpool-II-30-3.* pgpool-II-3.*
USE_RC_SUBR=	pgpool

DOCS=		AUTHORS COPYING ChangeLog INSTALL NEWS README README.euc_jp \
		TODO doc/pgpool-en.html doc/pgpool-ja.html doc/pgpool.css \
		doc/tutorial-en.html doc/tutorial-ja.html

OPTIONS_DEFINE+=	DOCS SSL LIBMEMCACHED PAM
OPTIONS_DEFAULT=	SSL PAM

# Buggy configure: adding eg. --without-pam to CONFIGURE_ARGS causes
# USE_PAM to be *defined* in config.h Omit the --with-pam or
# --without-pam flags entirely to leave PAM turned off.  Similarly for
# --with-memcached.

LIBMEMCACHED_DESC=		Build with MemCached support
LIBMEMCACHED_BUILD_DEPENDS=	libmemcached>=1.0:databases/libmemcached
LIBMEMCACHED_CONFIGURE_ON=	--with-memcached=${LOCALBASE}/lib/libmemcached

SSL_CONFIGURE_WITH=	openssl
SSL_USE=		OPENSSL=yes

PAM_DESC=		Build with PAM support
PAM_CONFIGURE_ON=	--with-pam
PAM_USE=		PAM=yes

FUNC_CONTRIB_DIR=	${PREFIX}/share/postgresql/contrib
FUNC_LIB_DIR=		${PREFIX}/lib/postgresql

FUNCTIONS=		pgpool-recovery pgpool-regclass
FUNC_CONTRIB=		pgpool-recovery/uninstall_pgpool-recovery.sql \
			pgpool-recovery/pgpool-recovery.sql \
			pgpool-regclass/uninstall_pgpool-regclass.sql \
			pgpool-regclass/pgpool-regclass.sql
FUNC_LIB=		pgpool-recovery/pgpool-recovery.so \
			pgpool-regclass/pgpool-regclass.so

post-build:
.for f in ${FUNCTIONS}
	cd ${WRKSRC}/sql/${f} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD}
.endfor

post-install:
	${MKDIR} ${STAGEDIR}${FUNC_CONTRIB_DIR}
.for f in ${FUNC_CONTRIB}
	${INSTALL_DATA} ${WRKSRC}/sql/${f} ${STAGEDIR}${FUNC_CONTRIB_DIR}
.endfor
	${MKDIR} ${STAGEDIR}${FUNC_LIB_DIR}
.for f in ${FUNC_LIB}
	${INSTALL_LIB} ${WRKSRC}/sql/${f} ${STAGEDIR}${FUNC_LIB_DIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/sample/dist_def_pgbench.sql \
	    ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sample/replicate_def_pgbench.sql \
	    ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in pgpool_recovery pgpool_recovery_pitr pgpool_remote_start
	${INSTALL_SCRIPT} ${WRKSRC}/sample/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_MAN} ${WRKSRC}/$f ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

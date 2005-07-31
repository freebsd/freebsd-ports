# New ports collection makefile for:	slony1
# Date created:		20 Jun 2004
# Whom:			Radim Kolar
#
# $FreeBSD$
#

PORTNAME=	slony1
PORTVERSION=	1.1.0
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://developer.postgresql.org/~wieck/slony1/download/

MAINTAINER=	vivek@khera.org
COMMENT=	PostgreSQL master to multiple replicas replication system

PGSQL_PORT=	${PORTSDIR}/databases/postgresql${PGSQL_VER}-server
RUN_DEPENDS=	${LOCALBASE}/bin/postmaster:${PGSQL_PORT}
BUILD_DEPENDS=	${LOCALBASE}/bin/postmaster:${PGSQL_PORT}

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_RC_SUBR=	slon.sh

SUB_FILES=	pkg-message slon-mkservice.sh
SUB_LIST+=	NAME=slon

OPTIONS=	PERLTOOLS "Install perl configuration tools" Off

.include <bsd.port.pre.mk>

.if defined(WITH_PERLTOOLS)
USE_PERL5_RUN=	yes
CONFIGURE_ARGS+=	--with-perltools=${LOCALBASE}/sbin
PLIST_SUB+=	PERLTOOLS=""
SUB_LIST+=	PERLTOOLS=""
.else
PLIST_SUB+=	PERLTOOLS="@comment "
SUB_LIST+=	PERLTOOLS="@comment "
.endif

DEFAULT_PGSQL_VER?=80

# Setting/finding PostgreSQL version we want.
.if exists(${LOCALBASE}/bin/postmaster)
PGSQL_VER!=	${LOCALBASE}/bin/postmaster -V | \
		${SED} -En 's/postmaster.*PostgreSQL[^0-9]*([0-9]+)\.([0-9]+)\..*/\1\2/p'
.elif exists(${LOCALBASE}/bin/pg_config)
PGSQL_VER!=	${LOCALBASE}/bin/pg_config --version | \
		${SED} -En 's/PostgreSQL[^0-9]*([0-9]*)\.([0-9]+)\..*/\1\2/p'
.else
PGSQL_VER=	${DEFAULT_PGSQL_VER}
.endif

post-install:
.if ! defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/adminguide
	${MKDIR} ${DOCSDIR}/howto
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${WRKSRC}/INSTALL ${WRKSRC}/SAMPLE ${WRKSRC}/README ${WRKSRC}/HISTORY-1.1 ${WRKSRC}/UPGRADING ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*/*.pdf ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/howto/*.txt ${WRKSRC}/doc/howto/*.html ${DOCSDIR}/howto/
	${INSTALL_DATA} ${WRKSRC}/doc/adminguide/prebuilt/*.html ${DOCSDIR}/adminguide/
.endif
	@${INSTALL_SCRIPT} ${WRKDIR}/slon-mkservice.sh ${PREFIX}/sbin/slon-mkservice
	@${INSTALL_DATA} ${FILESDIR}/slon.conf-sample ${PREFIX}/etc/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

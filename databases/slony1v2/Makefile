# Created by: Radim Kolar
# $FreeBSD$

PORTNAME=	slony1v2
PORTVERSION=	2.1.3
CATEGORIES=	databases
MASTER_SITES=	http://main.slony.info/downloads/2.1/source/
DISTNAME=	slony1-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME}-docs${EXTRACT_SUFX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	PostgreSQL master to multiple replicas replication system

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex \
		${LOCALBASE}/bin/postmaster:${PORTSDIR}/databases/postgresql${PGSQL_VER}-server

GNU_CONFIGURE=	yes
USES=		bison gmake
USE_PGSQL=	yes
USE_BZIP2=	yes
USE_RC_SUBR=	slon

SUB_FILES=	pkg-message slon-mkservice.sh
SUB_LIST+=	NAME=slon

OPTIONS_DEFINE=	DOCS PERLTOOLS
PERLTOOLS_DESC=	Install perl configuration tools

CONFLICTS?=	slony1-1*

CONFIGURE_ENV+=	FLEX=${LOCALBASE}/bin/flex

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPERLTOOLS}
USES+=		perl5
CONFIGURE_ARGS+=--with-perltools=${LOCALBASE}/sbin
RUN_DEPENDS+=	p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg
BUILD_DEPENDS+=	p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg
PLIST_SUB+=	PERLTOOLS=""
SUB_LIST+=	PERLTOOLS=""
.else
PLIST_SUB+=	PERLTOOLS="@comment "
SUB_LIST+=	PERLTOOLS="@comment "
.endif

# let configure find postgres stuff in non-standard places
CONFIGURE_ARGS+=--with-pgconfigdir=${LOCALBASE}/bin \
		--with-pgbindir=${LOCALBASE}/bin \
		--with-pgincludedir=${LOCALBASE}/include \
		--with-pgincludeserverdir=${LOCALBASE}/include/postgresql/server \
		--with-pglibdir=${LOCALBASE}/lib \
		--with-pgpkglibdir=${LOCALBASE}/lib/postgresql \
		--with-pgsharedir=${LOCALBASE}/share/postgresql

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		slon.1 slonik.1
.endif

# Setting/finding PostgreSQL version we want.
.if exists(${LOCALBASE}/bin/postmaster)
PGSQL_VER!=	${LOCALBASE}/bin/postmaster -V | \
		${SED} -En 's/.*PostgreSQL[^0-9]*([0-9]+)\.([0-9]+)\..*/\1\2/p'
.elif exists(${LOCALBASE}/bin/pg_config)
PGSQL_VER!=	${LOCALBASE}/bin/pg_config --version | \
		${SED} -En 's/PostgreSQL[^0-9]*([0-9]*)\.([0-9]+)\..*/\1\2/p'
.else
PGSQL_VER=	${DEFAULT_PGSQL_VER}
.endif

PORTDOCS=	*

DOCS=		COPYRIGHT HISTORY-1.1 INSTALL README README.Unicode RELEASE \
		RELEASE-2.0 SAMPLE TODO UPGRADING

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/adminguide
	@${MKDIR} ${DOCSDIR}/howto
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${INSTALL_DATA} ${WRKSRC}/doc/howto/*.txt ${WRKSRC}/doc/howto/*.html ${DOCSDIR}/howto/
	@${INSTALL_DATA} ${WRKSRC}/doc/adminguide/*.html ${WRKSRC}/doc/adminguide/*.png ${DOCSDIR}/adminguide/
.endif
.if ! defined(NO_INSTALL_MANPAGES)
	@${INSTALL_MAN} ${WRKSRC}/doc/adminguide/man1/*.1 ${MAN1PREFIX}/man/man1
.endif
	@${INSTALL_SCRIPT} ${WRKDIR}/slon-mkservice.sh ${PREFIX}/sbin/slon-mkservice
	@${INSTALL_DATA} ${FILESDIR}/slon.conf-sample ${PREFIX}/etc/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

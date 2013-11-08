# Created by: Radim Kolar
# $FreeBSD$

PORTNAME=	slony1v2
PORTVERSION=	2.2.1
CATEGORIES=	databases
MASTER_SITES=	http://main.slony.info/downloads/2.2/source/
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

DOCS=		COPYRIGHT INSTALL README README.Unicode RELEASE \
		SAMPLE TODO UPGRADING

post-patch:
	@for _file in ${WRKSRC}/doc/adminguide/man7/*.7; do \
		mv "$${_file}" $$(echo $${_file} | sed -e 's/ [ ]*/_/g'); \
	done
	@for _file in ${WRKSRC}/doc/adminguide/man7/*.7; do \
		${REINPLACE_CMD} -e '/^.TH/s/  [ ]*/ /g' $${_file}; \
	done

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/adminguide
.for _file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${_file} ${STAGEDIR}${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/adminguide/*.html ${WRKSRC}/doc/adminguide/*.png ${STAGEDIR}${DOCSDIR}/adminguide/
	${INSTALL_MAN} ${WRKSRC}/doc/adminguide/man1/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/adminguide/man7/*.7 ${STAGEDIR}${MAN1PREFIX}/man/man7
	${INSTALL_SCRIPT} ${WRKDIR}/slon-mkservice.sh ${STAGEDIR}${PREFIX}/sbin/slon-mkservice
	${INSTALL_DATA} ${FILESDIR}/slon.conf-sample ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>

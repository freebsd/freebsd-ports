# Created by: Radim Kolar
# $FreeBSD$

PORTNAME=	slony1v2
PORTVERSION=	2.2.10
CATEGORIES=	databases
MASTER_SITES=	http://main.slony.info/downloads/2.2/source/
DISTNAME=	slony1-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME}-docs${EXTRACT_SUFX}

MAINTAINER=	dgilbert@eicat.ca
COMMENT=	PostgreSQL master to multiple replicas replication system

LICENSE=	PostgreSQL
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex

GNU_CONFIGURE=	yes
USES=		bison gmake shebangfix tar:bzip2 pgsql
WANT_PGSQL=	server
USE_RC_SUBR=	slon
SHEBANG_FILES=	tools/altperl/slonik_restart_node.pl

SUB_FILES=	pkg-message slon-mkservice.sh
SUB_LIST+=	NAME=slon

OPTIONS_DEFINE=	DOCS PERLTOOLS
OPTIONS_SUB=	yes
PERLTOOLS_DESC=	Install perl configuration tools

CONFLICTS?=	slony1-1*

CONFIGURE_ENV+=	FLEX=${LOCALBASE}/bin/flex

PERLTOOLS_USES=	perl5
PERLTOOLS_CONFIGURE_ENV=	PERL=${PERL}
PERLTOOLS_CONFIGURE_ON=		--with-perltools=${LOCALBASE}/sbin
PERLTOOLS_BUILD_DEPENDS=	p5-DBD-Pg>=0:databases/p5-DBD-Pg
PERLTOOLS_RUN_DEPENDS=		p5-DBD-Pg>=0:databases/p5-DBD-Pg

# let configure find postgres stuff in non-standard places
CONFIGURE_ARGS+=--with-pgconfigdir=${LOCALBASE}/bin \
		--with-pgbindir=${LOCALBASE}/bin \
		--with-pgincludedir=${LOCALBASE}/include \
		--with-pgincludeserverdir=${LOCALBASE}/include/postgresql/server \
		--with-pglibdir=${LOCALBASE}/lib \
		--with-pgpkglibdir=${LOCALBASE}/lib/postgresql \
		--with-pgsharedir=${LOCALBASE}/share/postgresql

PORTDOCS=	*

DOCS=		README README.Unicode RELEASE \
		SAMPLE TODO UPGRADING

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/slon
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/slonik
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/slony_logshipper
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/*.so
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/adminguide
.for _file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${_file} ${STAGEDIR}${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/adminguide/*.html ${WRKSRC}/doc/adminguide/*.png ${STAGEDIR}${DOCSDIR}/adminguide/
	${INSTALL_SCRIPT} ${WRKDIR}/slon-mkservice.sh ${STAGEDIR}${PREFIX}/sbin/slon-mkservice
	${INSTALL_DATA} ${FILESDIR}/slon.conf-sample ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>

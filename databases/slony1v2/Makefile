# Created by: Radim Kolar
# $FreeBSD$

PORTNAME=	slony1v2
PORTVERSION=	2.2.4
CATEGORIES=	databases
MASTER_SITES=	http://main.slony.info/downloads/2.2/source/
DISTNAME=	slony1-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME}-docs${EXTRACT_SUFX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	PostgreSQL master to multiple replicas replication system

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

PERLTOOLS_DESC=	Install perl configuration tools
PERLTOOLS_USES=	perl5
PERLTOOLS_CONFIGURE_ENV=	PERL=${PERL}
PERLTOOLS_CONFIGURE_ON=		--with-perltools=${LOCALBASE}/sbin
PERLTOOLS_BUILD_DEPENDS=	p5-DBD-Pg>=0:databases/p5-DBD-Pg
PERLTOOLS_RUN_DEPENDS=		p5-DBD-Pg>=0:databases/p5-DBD-Pg

.include <bsd.port.options.mk>

# let configure find postgres stuff in non-standard places
CONFIGURE_ARGS+=--with-pgconfigdir=${LOCALBASE}/bin \
		--with-pgbindir=${LOCALBASE}/bin \
		--with-pgincludedir=${LOCALBASE}/include \
		--with-pgincludeserverdir=${LOCALBASE}/include/postgresql/server \
		--with-pglibdir=${LOCALBASE}/lib \
		--with-pgpkglibdir=${LOCALBASE}/lib/postgresql \
		--with-pgsharedir=${LOCALBASE}/share/postgresql

PORTDOCS=	*

DOCS=		COPYRIGHT INSTALL README README.Unicode RELEASE \
		SAMPLE TODO UPGRADING

post-patch:
	@for _file in ${WRKSRC}/doc/adminguide/man7/*.7; do \
		${MV} "$${_file}" $$(echo $${_file} | ${SED} -e 's/ [ ]*/_/g'); \
	done
	@for _file in ${WRKSRC}/doc/adminguide/man7/*.7; do \
		${REINPLACE_CMD} -e '/^.TH/s/  [ ]*/ /g' $${_file}; \
	done

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
	${INSTALL_MAN} ${WRKSRC}/doc/adminguide/man1/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/adminguide/man7/*.7 ${STAGEDIR}${MAN1PREFIX}/man/man7
	${INSTALL_SCRIPT} ${WRKDIR}/slon-mkservice.sh ${STAGEDIR}${PREFIX}/sbin/slon-mkservice
	${INSTALL_DATA} ${FILESDIR}/slon.conf-sample ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	neo4j
DISTVERSION=	3.3.2
CATEGORIES=	databases java
MASTER_SITES=	http://dist.neo4j.org/
DISTNAME=	${PORTNAME}-community-${DISTVERSION}-unix

MAINTAINER=	jonathan@FreeBSD.org
COMMENT=	High performance graph store and database

LICENSE=	GPLv3

RUN_DEPENDS=	bash:shells/bash

WRKSRC=		${WRKDIR}/${DISTNAME:S,-unix,,}
NO_BUILD=	yes
USES=		shebangfix
SHEBANG_FILES=	bin/cypher-shell bin/neo4j-admin bin/neo4j-shell bin/neo4j-import
USE_JAVA=	yes
USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	LOGDIR=${LOGDIR} RUNDIR=${RUNDIR}

PLIST_SUB=	DBDIR=${DBDIR} DISTVERSION=${DISTVERSION}

DBDIR=		${DESTDIR}/var/db/${PORTNAME}
LOGDIR=		${DESTDIR}/var/log/${PORTNAME}
RUNDIR=		${DESTDIR}/var/run/

post-patch:
	${REINPLACE_CMD} 's,%%DBDIR%%,${DBDIR},g;s,%%JAVA_HOME%%,${JAVA_HOME},g;s,%%LOGDIR%%,${LOGDIR},g;s,%%PREFIX%%,${PREFIX},g;s,%%RUNDIR%%,${RUNDIR},g' \
		${WRKSRC}/bin/cypher-shell ${WRKSRC}/bin/neo4j* \
		${WRKSRC}/conf/neo4j.conf

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}/libexec/tools
	${INSTALL_SCRIPT} ${WRKSRC}/bin/tools/* \
		${STAGEDIR}${PREFIX}/${PORTNAME}/libexec/tools
.for name in cypher-shell neo4j neo4j-admin neo4j-import neo4j-shell
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${name} ${STAGEDIR}${PREFIX}/bin
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}/lib/plugins
	${INSTALL_SCRIPT} ${WRKSRC}/lib/* ${STAGEDIR}${PREFIX}/${PORTNAME}/lib
.for f in ${PORTNAME}.conf
	${INSTALL_DATA} ${WRKSRC}/conf/$f \
		${STAGEDIR}${PREFIX}/etc/$f.sample
.endfor
	${MKDIR} ${STAGEDIR}${DBDIR} ${STAGEDIR}${PREFIX}/etc/neo4j-certificates
.include <bsd.port.mk>

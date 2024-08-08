PORTNAME=	neo4j
DISTVERSION=	4.4.35
CATEGORIES=	databases java
MASTER_SITES=	http://dist.neo4j.org/
DISTNAME=	${PORTNAME}-community-${DISTVERSION}-unix

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High performance graph store and database
WWW=		https://neo4j.com

LICENSE=	GPLv3

RUN_DEPENDS=	bash:shells/bash

WRKSRC=		${WRKDIR}/${DISTNAME:S,-unix,,}
NO_BUILD=	yes
USES=		cpe shebangfix
SHEBANG_FILES=	bin/cypher-shell bin/neo4j-admin
USE_JAVA=	yes
JAVA_VERSION=	11
USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	LOGDIR=${LOGDIR} RUNDIR=${RUNDIR}

PLIST_SUB=	DBDIR=${DBDIR} DISTVERSION=${DISTVERSION}

DBDIR=		${DESTDIR}/var/db/${PORTNAME}
LOGDIR=		${DESTDIR}/var/log/${PORTNAME}
RUNDIR=		${DESTDIR}/var/run/
NEO4JDIR=	${PREFIX}/${PORTNAME}
NEO4J_CONFDIR=	${PREFIX}/etc

post-patch:
	${REINPLACE_CMD} 's,%%DBDIR%%,${DBDIR},g;s,%%JAVA_HOME%%,${JAVA_HOME},g;s,%%LOGDIR%%,${LOGDIR},g;s,%%PREFIX%%,${PREFIX},g;s,%%RUNDIR%%,${RUNDIR},g' \
		${WRKSRC}/bin/cypher-shell ${WRKSRC}/bin/neo4j* \
		${WRKSRC}/conf/neo4j.conf

	${REINPLACE_CMD} 's,%%NEO4JDIR%%,${NEO4JDIR},g;s,%%NEO4J_CONFDIR%%,${NEO4J_CONFDIR},g' \
		${WRKSRC}/bin/neo4j

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}/libexec/tools
	${INSTALL_SCRIPT} ${WRKSRC}/bin/tools/* \
		${STAGEDIR}${PREFIX}/${PORTNAME}/libexec/tools
.for name in cypher-shell neo4j neo4j-admin
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

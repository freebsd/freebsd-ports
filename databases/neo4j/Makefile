PORTNAME=	neo4j
DISTVERSION=	4.4.44
PORTREVISION=	1
CATEGORIES=	databases java
MASTER_SITES=	http://dist.neo4j.org/
DISTNAME=	${PORTNAME}-community-${DISTVERSION}-unix

MAINTAINER=	otis@FreeBSD.org
COMMENT=	High performance graph store and database
WWW=		https://neo4j.com

# Bouncy Castle License is in fact MIT.
# Scala is licensed under BSD3CLAUSE.
# Java Servlet API is licensed under CDDL and GPLv2wCE
LICENSE=	APACHE20 BSD2CLAUSE BSD3CLAUSE CDDL GPLv2wCE GPLv3 ISCL MIT MPL20 OFL11
LICENSE_COMB=	multi
LICENSE_NAME_GPLv2wCE=	GPLv2 with Classpath Exception
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSE.txt
LICENSE_FILE=	${WRKSRC}/LICENSES.txt
LICENSE_PERMS_GPLv2wCE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cpe java shebangfix
JAVA_VERSION=	11
USE_RC_SUBR=	${PORTNAME}

SHEBANG_FILES=	bin/cypher-shell bin/neo4j-admin

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	JAVA_HOME=${JAVA_HOME} \
		LOGDIR=${LOGDIR} \
		RUNDIR=${RUNDIR}

WRKSRC=		${WRKDIR}/${DISTNAME:S,-unix,,}

USERS?=		neo4j
GROUPS?=	neo4j

PLIST_SUB=	CERTDIR=${CERTDIR} \
		DBDATADIR=${DBDATADIR} \
		DBDIR=${DBDIR} \
		DBIMPORTDIR=${DBIMPORTDIR} \
		DISTVERSION=${DISTVERSION} \
		GROUPS=${GROUPS} \
		METRICSDIR=${METRICSDIR} \
		USERS=${USERS}

CERTDIR=	${ETCDIR}/certificates
DBDATADIR=	${DBDIR}/data
DBDIR=		${DESTDIR}/var/db/${PORTNAME}
DBIMPORTDIR=	${DBDIR}/import
LOGDIR=		${DESTDIR}/var/log/${PORTNAME}
METRICSDIR=	${DBDIR}/metrics
RUNDIR=		${DESTDIR}/var/run/${PORTNAME}
NEO4JDIR=	${PREFIX}/${PORTNAME}
NEO4J_CONFDIR=	${PREFIX}/etc/neo4j

post-patch:
	${REINPLACE_CMD} 's,%%DBDATADIR%%,${DBDATADIR},g;s,%%DBDIR%%,${DBDIR},g;\
		s,%%JAVA_HOME%%,${JAVA_HOME},g;s,%%LOGDIR%%,${LOGDIR},g;s,%%PREFIX%%,${PREFIX},g;s,%%RUNDIR%%,${RUNDIR},g;\
		s,%%DBIMPORTDIR%%,${DBIMPORTDIR},g;s,%%CERTDIR%%,${CERTDIR},g' \
		${WRKSRC}/bin/cypher-shell ${WRKSRC}/bin/neo4j* \
		${WRKSRC}/conf/neo4j.conf

	${REINPLACE_CMD} 's,%%NEO4JDIR%%,${NEO4JDIR},g;s,%%NEO4J_CONFDIR%%,${NEO4J_CONFDIR},g' \
		${WRKSRC}/bin/neo4j

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
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
		${STAGEDIR}${ETCDIR}/$f.sample
.endfor
	${MKDIR} ${STAGEDIR}${DBDIR} \
		${STAGEDIR}${DBDATADIR} \
		${STAGEDIR}${DBIMPORTDIR} \
		${STAGEDIR}${METRICSDIR} \
		${STAGEDIR}${CERTDIR}

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	puppetdb
PORTVERSION=	3.2.4
CATEGORIES=	databases java
MASTER_SITES=	http://downloads.puppetlabs.com/puppetdb/
PKGNAMESUFFIX=	3

MAINTAINER=	freebsd@zleslie.info
COMMENT=	PuppetDB storeconfigs backend

LICENSE=	APACHE20

RUN_DEPENDS=	bash:shells/bash \
		puppet:sysutils/puppet4
BUILD_DEPENDS=	rubygem-facter>=0:sysutils/rubygem-facter \
		rubygem-rake>=0:devel/rubygem-rake

USE_RC_SUBR=	puppetdb

CONFLICTS_INSTALL=	puppetdb-* puppetdb4-*
USE_JAVA=	yes
NO_BUILD=	yes
JAVA_VERSION=	1.7+

USERS=		puppetdb
GROUPS=		puppetdb

SUB_LIST=	JAVA_HOME=${JAVA_HOME}
SUB_FILES=	pkg-message

PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

post-patch:
.for file in ext/config/bootstrap.cfg ext/config/logback.xml \
	ext/config/request-logging.xml ext/config/conf.d/config.ini \
	ext/config/conf.d/database.ini ext/config/conf.d/jetty.ini \
	ext/config/conf.d/repl.ini ext/bin/puppetdb
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/${file}
	@${REINPLACE_CMD} -e "s|%%JAVA%%|${JAVA}|" ${WRKSRC}/${file}
	@${REINPLACE_CMD} -e "s|%%DATADIR%%|${DATADIR}|" ${WRKSRC}/${file}
	@${REINPLACE_CMD} -e "s|%%ETCDIR%%|${ETCDIR}|" ${WRKSRC}/${file}
.endfor

.for file in ext/cli/anonymize ext/cli/config-migration \
	ext/cli/export ext/cli/foreground ext/cli/import \
	ext/cli/ssl-setup
	@${REINPLACE_CMD} -e 's|/etc/puppetlabs/puppetdb|${ETCDIR}|g' ${WRKSRC}/${file}
	@${REINPLACE_CMD} -e 's|/bin/bash|${PREFIX}/bin/bash|g' ${WRKSRC}/${file}
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/cli
	${MKDIR} ${STAGEDIR}${DATADIR}/cli/apps
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${ETCDIR}/conf.d
	${MKDIR} ${STAGEDIR}/var/log/puppetdb
	${MKDIR} ${STAGEDIR}/var/db/puppetdb
	${INSTALL_DATA} ${WRKSRC}/puppetdb.jar ${STAGEDIR}${DATADIR}/puppetdb.jar
	${INSTALL_DATA} ${WRKSRC}/ext/config/conf.d/config.ini ${STAGEDIR}${ETCDIR}/conf.d/config.ini.sample
	${INSTALL_DATA} ${WRKSRC}/ext/config/conf.d/database.ini ${STAGEDIR}${ETCDIR}/conf.d/database.ini.sample
	${INSTALL_DATA} ${WRKSRC}/ext/config/conf.d/jetty.ini ${STAGEDIR}${ETCDIR}/conf.d/jetty.ini.sample
	${INSTALL_DATA} ${WRKSRC}/ext/config/conf.d/repl.ini ${STAGEDIR}${ETCDIR}/conf.d/repl.ini.sample
	${INSTALL_DATA} ${WRKSRC}/ext/config/bootstrap.cfg ${STAGEDIR}${ETCDIR}/bootstrap.cfg.sample
	${INSTALL_DATA} ${WRKSRC}/ext/config/logback.xml ${STAGEDIR}${ETCDIR}/logback.xml.sample
	${INSTALL_DATA} ${WRKSRC}/ext/config/request-logging.xml ${STAGEDIR}${ETCDIR}/request-logging.xml.sample
	${INSTALL_DATA} ${WRKSRC}/ext/cli/anonymize ${STAGEDIR}${DATADIR}/cli/apps/anonymize
	${INSTALL_DATA} ${WRKSRC}/ext/cli/config-migration ${STAGEDIR}${DATADIR}/cli/apps/config-migration
	${INSTALL_DATA} ${WRKSRC}/ext/cli/export ${STAGEDIR}${DATADIR}/cli/apps/export
	${INSTALL_DATA} ${WRKSRC}/ext/cli/foreground ${STAGEDIR}${DATADIR}/cli/apps/foreground
	${INSTALL_DATA} ${WRKSRC}/ext/cli/import ${STAGEDIR}${DATADIR}/cli/apps/import
	${INSTALL_DATA} ${WRKSRC}/ext/cli/ssl-setup ${STAGEDIR}${DATADIR}/cli/apps/ssl-setup
	${INSTALL_DATA} ${WRKSRC}/ext/bin/puppetdb ${STAGEDIR}${PREFIX}/sbin/puppetdb

.include <bsd.port.post.mk>

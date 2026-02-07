PORTNAME=	openvoxdb
PORTVERSION=	8.11.0
CATEGORIES=	databases java
MASTER_SITES=	https://artifacts.voxpupuli.org/${PORTNAME}/${PORTVERSION}/
PKGNAMESUFFIX=	8

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	PuppetDB storeconfigs backend
WWW=		https://docs.puppetlabs.com/puppetdb/latest/

LICENSE=	APACHE20

RUN_DEPENDS=	bash:shells/bash

USE_RC_SUBR=	puppetdb

CONFLICTS_INSTALL=	openvoxdb[0-9] puppetdb[0-9] # etc/puppetdb/bootstrap.cfg.sample
USES=		cpe java shebangfix
CPE_VENDOR=	puppet
SHEBANG_FILES=	ext/bin/puppetdb \
		ext/cli/anonymize \
		ext/cli/config-migration \
		ext/cli/foreground \
		ext/cli/ssl-setup \
		ext/cli/upgrade
JAVA_VERSION=	11+
NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/puppetdb-${PORTVERSION}

USERS=		puppetdb
GROUPS=		puppetdb

SUB_LIST=	JAVA_HOME=${JAVA_HOME}
SUB_FILES=	pkg-message

DATADIR=	${PREFIX}/share/puppetdb
ETCDIR=		${PREFIX}/etc/puppetdb

post-patch:
.for file in ext/bin/puppetdb ext/cli/ssl-setup \
	ext/config/conf.d/jetty.ini ext/config/conf.d/config.ini
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/${file}
.endfor
	@${REINPLACE_CMD} -e "s|%%DATADIR%%|${DATADIR}|" ${WRKSRC}/ext/bin/puppetdb
	${FIND} ${WRKSRC}/ext/cli ${WRKSRC}/ext/config \( -name \*.bak -o -name \*.orig \) -delete
	${FIND} ${WRKSRC}/ext/config -type f -print0 | ${XARGS} -0 -I {} ${MV} {} {}.sample

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ext/bin/puppetdb ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${ETCDIR}
	cd ${WRKSRC}/ext/config && ${COPYTREE_SHARE} \* ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/cli/apps
	cd ${WRKSRC} && ${COPYTREE_SHARE} puppetdb.jar ${STAGEDIR}${DATADIR}
.for file in ext/cli/anonymize ext/cli/config-migration ext/cli/delete-reports ext/cli/foreground ext/cli/ssl-setup ext/cli/upgrade
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${STAGEDIR}${DATADIR}/cli/apps
.endfor

.include <bsd.port.mk>

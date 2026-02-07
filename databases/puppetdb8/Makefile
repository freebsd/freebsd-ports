PORTNAME=	puppetdb
PORTVERSION=	8.8.1
CATEGORIES=	databases java
MASTER_SITES=	https://downloads.puppetlabs.com/puppetdb/
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
		ext/cli/start \
		ext/cli/stop \
		ext/cli/reload \
		ext/cli/upgrade \
		ext/ezbake-functions.sh
JAVA_VERSION=	11+
NO_ARCH=	yes
NO_BUILD=	yes

USERS=		puppetdb
GROUPS=		puppetdb

SUB_LIST=	JAVA_HOME=${JAVA_HOME}
SUB_FILES=	pkg-message

post-patch:
.for file in Makefile ext/bin/puppetdb ext/cli/ssl-setup \
	ext/config/conf.d/jetty.ini ext/config/conf.d/config.ini
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/${file}
.endfor
	@${REINPLACE_CMD} -e "s|%%DATADIR%%|${DATADIR}|" ${WRKSRC}/ext/bin/puppetdb
	@${REINPLACE_CMD} -e 's|/puppetlabs/puppetdb/|/puppetdb/|' \
		-e 's|\(install -m 0644 ext/config/.*\)"|\1.sample"|' \
		${WRKSRC}/Makefile

do-install:
	@cd ${WRKSRC} && ${SETENV} DESTDIR=${STAGEDIR} make install-puppetdb

.include <bsd.port.mk>

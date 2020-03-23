# $FreeBSD$

PORTNAME=	puppetdb
PORTVERSION=	5.2.13
CATEGORIES=	databases java
MASTER_SITES=	https://downloads.puppetlabs.com/puppetdb/
PKGNAMESUFFIX=	5

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	PuppetDB storeconfigs backend

LICENSE=	APACHE20

RUN_DEPENDS=	bash:shells/bash

USE_RC_SUBR=	puppetdb

CONFLICTS_INSTALL=	puppetdb4-* puppetdb5-*
USES=		shebangfix
SHEBANG_FILES=	ext/bin/puppetdb \
		ext/cli/anonymize \
		ext/cli/config-migration \
		ext/cli/foreground \
		ext/cli/upgrade \
		ext/cli/ssl-setup \
		ext/cli/start \
		ext/cli/stop \
		ext/cli/reload \
		ext/ezbake-functions.sh
USE_JAVA=	yes
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

do-install:
	@cd ${WRKSRC} && ${SETENV} DESTDIR=${STAGEDIR} make install-puppetdb

.include <bsd.port.mk>

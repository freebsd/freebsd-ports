# $FreeBSD$

PORTNAME=	puppetdb
PORTVERSION=	2.3.8
PORTREVISION=	1
CATEGORIES=	databases java
MASTER_SITES=	http://downloads.puppetlabs.com/puppetdb/

MAINTAINER=	xaque208@gmail.com
COMMENT=	PuppetDB storeconfigs backend

LICENSE=	APACHE20

RUN_DEPENDS=	bash:shells/bash \
		puppet:sysutils/puppet38
BUILD_DEPENDS=	rubygem-facter>=0:sysutils/rubygem-facter \
		rubygem-rake>=0:devel/rubygem-rake

USE_RC_SUBR=	puppetdb

CONFLICTS_INSTALL=	puppetdb3-* puppetdb4-*
USES=		shebangfix
SHEBANG_FILES=	ext/files/puppetdb \
		ext/files/puppetdb-anonymize \
		ext/files/puppetdb-export \
		ext/files/puppetdb-foreground \
		ext/files/puppetdb-import \
		ext/files/puppetdb-legacy \
		ext/files/puppetdb-ssl-setup
USE_JAVA=	yes
NO_ARCH=	yes
NO_BUILD=	yes
JAVA_VERSION=	1.7+

USERS=		puppetdb
GROUPS=		puppetdb

SUB_LIST=	JAVA_HOME=${JAVA_HOME}
SUB_FILES=	pkg-message

PKGMESSAGE=	${WRKDIR}/pkg-message

post-patch:
.for file in tasks/install.rake ext/files/config.ini ext/files/puppetdb \
	ext/files/puppetdb-import ext/files/puppetdb-anonymize \
	ext/files/database.ini ext/files/puppetdb-ssl-setup \
	ext/files/puppetdb-export ext/files/puppetdb-foreground Rakefile
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/${file}
.endfor

do-install:
	@cd ${WRKSRC} && ${SETENV} DESTDIR=${STAGEDIR} rake install

.include <bsd.port.mk>

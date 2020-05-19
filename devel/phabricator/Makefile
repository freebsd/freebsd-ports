# $FreeBSD$

PORTNAME=	phabricator
PORTVERSION=	20200514
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Open source, software engineering platform

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

IGNORE_WITH_PHP=74

RUN_DEPENDS=	arcanist-lib${PHP_PKGNAMESUFFIX}>=20200514:devel/arcanist-lib@${PHP_FLAVOR} \
		git:devel/git

USES=		php:flavors shebangfix

REINPLACE_ARGS=	-i ""
SHEBANG_FILES=	resources/timezones/*.php \
		scripts/*.php \
		scripts/almanac/*.php \
		scripts/cache/*.php \
		scripts/celerity/*.php \
		scripts/daemon/*.php \
		scripts/daemon/exec/exec_daemon.php \
		scripts/diviner/*.php \
		scripts/drydock/*.php \
		scripts/fact/*.php \
		scripts/files/*.php \
		scripts/install/install_rhel-derivs.sh \
		scripts/install/install_ubuntu.sh \
		scripts/lipsum/*.php \
		scripts/mail/*.php \
		scripts/repository/*.php \
		scripts/search/*.php \
		scripts/setup/*.php \
		scripts/ssh/*.php \
		scripts/sql/*.php \
		scripts/ssh/*.php \
		scripts/symbols/*.php \
		scripts/util/*.php \
		support/aphlict/server/*.php

USE_PHP=	ctype curl fileinfo filter hash iconv mbstring mysqli openssl \
		pcntl posix zip

OPTIONS_DEFINE=	GD OPCACHE
OPTIONS_DEFAULT=GD OPCACHE
OPCACHE_DESC?=	Use OPcache to improve performance

GD_USE=		PHP=gd

OPCACHE_RUN_DEPENDS=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/apcu.so:devel/pecl-APCu@${PHP_FLAVOR}
OPCACHE_USE=		PHP=opcache

USE_GITHUB=	yes
NO_BUILD=	yes
USE_RC_SUBR=	phd
SUB_FILES=	pkg-message
PORTSCOUT=	ignore:1
GH_ACCOUNT=	phacility
GH_TAGNAME=	3ee6b53

PHP_DESTDIR=	lib/php/phabricator

post-patch:
	@${SED} 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${FILESDIR}/phabricator-sudoers.sample > ${WRKSRC}/resources/sshd/phabricator-sudoers.sample
	@${REINPLACE_CMD} \
		's|/path/to/phabricator|${LOCALBASE}/lib/php/phabricator|g; \
		 s|vcs-user|git|g' \
		${WRKSRC}/resources/sshd/phabricator-ssh-hook.sh
	@${REINPLACE_CMD} \
		's|/usr/libexec/phabricator-ssh-hook.sh|${LOCALBASE}/lib/php/phabricator/resources/sshd/phabricator-ssh-hook.sh|; \
		 s|vcs-user|git|g; \
		 s|PrintLastLog no||g; \
		 s|PidFile /var/run/sshd-phabricator.pid||g' \
		${WRKSRC}/resources/sshd/sshd_config.phabricator.example
	@${REINPLACE_CMD} \
		's|%%PHP_CMD%%|${PREFIX}/bin/php|g' \
		${WRKSRC}/scripts/celerity/install_merge.sh \
		${WRKSRC}/src/infrastructure/testing/fixture/PhabricatorStorageFixtureScopeGuard.php

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}/conf/local
	${INSTALL_DATA} ${FILESDIR}/local.json.sample \
		${STAGEDIR}${PREFIX}/${PHP_DESTDIR}/conf/local
	cd ${WRKSRC} ; ${PAX} -rw * ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}

.include <bsd.port.mk>

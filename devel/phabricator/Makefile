PORTNAME=	phabricator
PORTVERSION=	20211218
PORTREVISION=	5
CATEGORIES=	devel
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Open source, software engineering platform
WWW=		https://www.phacility.com/phabricator/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	arcanist-lib${PHP_PKGNAMESUFFIX}>=20210113_4:devel/arcanist-lib@${PHP_FLAVOR} \
		git:devel/git

USES=		cpe dos2unix php:cli,flavors shebangfix
IGNORE_WITH_PHP=	85
CPE_VENDOR=	phacility
DOS2UNIX_FILES=	externals/phpmailer/class.smtp.php externals/phpqrcode/phpqrcode.php
USE_GITHUB=	yes
GH_ACCOUNT=	phacility
GH_TAGNAME=	dec9522
USE_PHP=	ctype curl fileinfo filter iconv mbstring mysqli pcntl posix \
		zip
USE_RC_SUBR=	phd

SHEBANG_FILES=	resources/timezones/*.php scripts/*.php scripts/almanac/*.php \
		scripts/cache/*.php scripts/celerity/*.php scripts/daemon/*.php \
		scripts/daemon/exec/exec_daemon.php scripts/diviner/*.php \
		scripts/drydock/*.php scripts/fact/*.php scripts/files/*.php \
		scripts/lipsum/*.php scripts/mail/*.php \
		scripts/repository/*.php scripts/search/*.php \
		scripts/setup/*.php scripts/sql/*.php scripts/ssh/*.php \
		scripts/symbols/*.php scripts/util/*.php \
		support/aphlict/server/*.php

NO_ARCH=	yes
NO_BUILD=	yes
PORTSCOUT=	ignore:1
SUB_FILES=	pkg-message

OPTIONS_DEFINE=		GD OPCACHE
OPTIONS_DEFAULT=	GD OPCACHE
OPCACHE_DESC?=		Use OPcache to improve performance

GD_USE=		PHP=gd

OPCACHE_RUN_DEPENDS=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/apcu.so:devel/pecl-APCu@${PHP_FLAVOR}
OPCACHE_USE=		PHP=opcache

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

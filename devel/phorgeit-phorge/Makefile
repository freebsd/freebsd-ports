PORTNAME=	phorge
PORTVERSION=	2025.18
PORTEPOCH=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	phorgeit
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Open source, software engineering platform
WWW=		https://www.phorge.it

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git \
		phorgeit-arcanist-lib${PHP_PKGNAMESUFFIX}>=2024.35,1:devel/phorgeit-arcanist-lib@${PHP_FLAVOR}

USES=		php:cli,flavors shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	phorgeit
USE_PHP=	ctype curl fileinfo filter iconv mbstring mysqli pcntl posix \
		zip
IGNORE_WITH_PHP=	84 85
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
CONFLICTS=	phabricator-php??

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

OPTIONS_DEFINE=		GD OPCACHE
OPTIONS_DEFAULT=	GD OPCACHE
OPCACHE_DESC?=		Use OPcache to improve performance

GD_USE=		PHP=gd

OPCACHE_RUN_DEPENDS=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/apcu.so:devel/pecl-APCu@${PHP_FLAVOR}
OPCACHE_USE=		PHP=opcache

PHP_DESTDIR=	lib/php/phorge

post-patch:
	@${SED} 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${FILESDIR}/phorge-sudoers.sample > ${WRKSRC}/resources/sshd/phorge-sudoers.sample
	@${REINPLACE_CMD} \
		's|/path/to/phorge|${LOCALBASE}/lib/php/phorge|g; \
		 s|vcs-user|git|g' \
		${WRKSRC}/resources/sshd/phorge-ssh-hook.sh
	@${REINPLACE_CMD} \
		's|/usr/libexec/phorge-ssh-hook.sh|${LOCALBASE}/lib/php/phorge/resources/sshd/phorge-ssh-hook.sh|; \
		 s|vcs-user|git|g; \
		 s|PrintLastLog no||g; \
		 s|PidFile /var/run/sshd-phorge.pid||g' \
		${WRKSRC}/resources/sshd/sshd_config.phorge.example
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

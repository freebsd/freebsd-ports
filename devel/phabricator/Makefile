# $FreeBSD$

PORTNAME=	phabricator
PORTVERSION=	20180420
CATEGORIES=	devel
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Open source, software engineering platform

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PHP_PKGNAMEPREFIX}libphutil>0:devel/libphutil@${PHP_FLAVOR} \
		arcanist${PHP_PKGNAMESUFFIX}>0:devel/arcanist@${PHP_FLAVOR} \
		git:devel/git

OPTIONS_DEFINE=	GD OPCACHE
OPTIONS_DEFAULT=GD OPCACHE
OPCACHE_DESC?=	Use OPcache to improve performance

USES=		php:flavors shebangfix
SHEBANG_FILES=	externals/httpful/build \
		externals/restful/build-phar \
		scripts/almanac/*.php \
		scripts/cache/*.php \
		scripts/celerity/*.php \
		scripts/daemon/*.php \
		scripts/diviner/*.php \
		scripts/drydock/*.php \
		scripts/fact/*.php \
		scripts/files/*.php \
		scripts/install/install_rhel-derivs.sh \
		scripts/install/install_ubuntu.sh \
		scripts/lipsum/*.php \
		scripts/mail/*.php \
		scripts/people/*.php \
		scripts/repository/*.php \
		scripts/search/*.php \
		scripts/setup/*.php \
		scripts/sms/*.php \
		scripts/sql/*.php \
		scripts/ssh/*.php \
		scripts/symbols/*.php \
		scripts/user/*.php \
		scripts/util/*.php \
		support/aphlict/server/*.php
USE_PHP=	ctype curl fileinfo filter hash iconv mbstring mysqli openssl \
		pcntl posix

GD_USE=		PHP=gd

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MOPCACHE}
USE_PHP+=	opcache
.	if ${PHP_VER} >= 70
RUN_DEPENDS+=	 ${PHPBASE}/lib/php/${PHP_EXT_DIR}/apcu.so:devel/pecl-APCu@${PHP_FLAVOR}
.	else
RUN_DEPENDS+=	 ${PHPBASE}/lib/php/${PHP_EXT_DIR}/apcu.so:devel/pecl-APCu4@${PHP_FLAVOR}
.	endif
.endif

USE_GITHUB=	yes
NO_BUILD=	yes
USE_RC_SUBR=	phd
SUB_FILES=	pkg-message
GH_ACCOUNT=	phacility
GH_TAGNAME=	9bf4df2

PHP_DESTDIR=	lib/php/phabricator

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}/conf/local
	@${INSTALL_DATA} ${FILESDIR}/local.json.sample \
		${STAGEDIR}${PREFIX}/${PHP_DESTDIR}/conf/local
	cd ${WRKSRC} ; ${PAX} -rw * ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}

.include <bsd.port.post.mk>

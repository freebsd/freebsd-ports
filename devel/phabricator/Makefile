# $FreeBSD$

PORTNAME=	phabricator
PORTVERSION=	20161003
PORTREVISION=	2
CATEGORIES=	devel
PKGNAMEPREFIX=	php-

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Open source, software engineering platform

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	php-libphutil>0:devel/libphutil \
		php-arcanist>0:devel/arcanist \
		git:devel/git

OPTIONS_DEFINE=	GD OPCACHE
OPTIONS_DEFAULT=OPCACHE
OPCACHE_DESC?=	Use OPcache to improve performance

USES=		php shebangfix
SHEBANG_FILES=	externals/httpful/build \
		externals/restful/build-phar \
		scripts/install/install_rhel-derivs.sh \
		scripts/install/install_ubuntu.sh
USE_PHP=	ctype curl fileinfo filter hash iconv mbstring mysqli openssl \
		pcntl posix

GD_USE=		PHP=gd

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MOPCACHE}
USE_PHP+=	opcache
.	if ${PHP_VER} >= 70
RUN_DEPENDS+=	 ${PHPBASE}/lib/php/${PHP_EXT_DIR}/apcu.so:devel/pecl-APCu
.	else
RUN_DEPENDS+=	 ${PHPBASE}/lib/php/${PHP_EXT_DIR}/apcu.so:devel/pecl-APCu4
.	endif
.endif

USE_GITHUB=	yes
NO_BUILD=	yes
USE_RC_SUBR=	phd
SUB_FILES=	pkg-message
GH_ACCOUNT=	phacility
GH_TAGNAME=	55a56c0

PHP_DESTDIR=	lib/php/phabricator

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}/conf/local
	@${INSTALL_DATA} ${FILESDIR}/local.json.sample \
		${STAGEDIR}${PREFIX}/${PHP_DESTDIR}/conf/local
	cd ${WRKSRC} ; ${PAX} -rw * ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}

.include <bsd.port.post.mk>

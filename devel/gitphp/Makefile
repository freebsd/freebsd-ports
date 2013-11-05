# $FreeBSD$

PORTNAME=	gitphp
PORTVERSION=	0.2.8
CATEGORIES=	devel www
MASTER_SITES=	http://www.gitphp.org/attachments/download/47/

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	A web based git repository browser written in PHP

LICENSE=	GPLv2

USE_BZIP2=	yes
USES=		gettext
USE_PHP=	bz2 fileinfo mbstring memcache posix simplexml spl zlib
WANT_PHP_WEB=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/xdiff.so:${PORTSDIR}/textproc/pecl-xdiff

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} \
		 && ${COPYTREE_SHARE} \* ${STAGEDIR}${WWWDIR})
	${CHOWN} -R www:www ${STAGEDIR}${WWWDIR}
	${FIND} ${STAGEDIR}${WWWDIR} -type f -exec ${CHMOD} 644 '{}' +

.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif
.include <bsd.port.mk>

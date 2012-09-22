# $FreeBSD$

PORTNAME=	gitphp
PORTVERSION=	0.2.7
CATEGORIES=	devel www
MASTER_SITES=	http://www.gitphp.org/attachments/download/42/

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	A web based git repository browser written in PHP

LICENSE=	GPLv2

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_PHP=	bz2 fileinfo mbstring memcache posix simplexml spl zlib
WANT_PHP_WEB=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${WWWDIR}
	(cd ${WRKSRC} \
		 && ${COPYTREE_SHARE} \* ${WWWDIR})
	${CHOWN} -R www:www ${WWWDIR}
	${FIND} ${WWWDIR} -type f -exec ${CHMOD} 644 '{}' +

.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif
.include <bsd.port.mk>

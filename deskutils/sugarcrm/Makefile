# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	sugarcrm
PORTVERSION=	6.5.15
CATEGORIES=	deskutils www
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/1%20-%20SugarCRM%206.5.X/SugarCommunityEdition-6.5.X
DISTNAME=	SugarCE-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Web based customer relationship management suite

USE_PHP=	gd mysql session pcre xml zlib mbstring curl imap spl posix
USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/SugarCE-Full-${PORTVERSION}

PKGMESSAGE=	${WRKDIR}/pkg-message

SUB_FILES+=	pkg-message pkg-install

do-install:
	@${MKDIR} ${STAGEDIR}/${WWWDIR}

	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}/${WWWDIR}/
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}/${WWWDIR}
	@${CHMOD} -R 755 ${STAGEDIR}/${WWWDIR}

.include <bsd.port.mk>

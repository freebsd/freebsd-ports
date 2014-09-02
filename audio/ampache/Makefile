# Created by: Philippe Audeoud <jadawin@tuxaco.net>
# $FreeBSD$

PORTNAME=	ampache
PORTVERSION=	3.5.4
PORTREVISION=	3
CATEGORIES=	audio www
MASTER_SITES=	http://ampache.org/downloads/

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Web-based Audio file manager

USE_PHP=	mysql pcre session iconv hash gettext mbstring
WANT_PHP_WEB=	yes

NO_BUILD=	yes
USES=		gettext

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message pkg-deinstall
PLIST_SUB=	WWWDIR=${WWWDIR} \
		WWWOWN=${WWWOWN} \
		WWWGRP=${WWWGRP}

PORTDOCS=	CHANGELOG README MIGRATION INSTALL

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/man/man1/ampache.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${doc} ${STAGEDIR}${DOCSDIR}
.endfor
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${WWWDIR} "! -name *.orig")

.include <bsd.port.mk>

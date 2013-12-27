# Created by: Philippe Audeoud <jadawin@tuxaco.net>
# $FreeBSD$

PORTNAME=	ampache
PORTVERSION=	3.5.4
PORTREVISION=	2
CATEGORIES=	audio www
MASTER_SITES=	http://ampache.org/downloads/

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	A Web-based Audio file manager

USE_PHP=	mysql pcre session iconv hash gettext mbstring
WANT_PHP_WEB=	yes

NO_BUILD=	yes
USES=		gettext

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message pkg-deinstall
SUB_LIST=	PORTNAME=${PORTNAME} \
		WWWDIR=${WWWDIR} \
		WWWOWN=${WWWOWN} \
		WWWGROUP=${WWWGROUP}

PORTDOCS=	CHANGELOG README MIGRATION INSTALL

.include <bsd.port.options.mk>

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/man/man1/ampache.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${doc} ${STAGEDIR}${DOCSDIR}
.endfor
.endif
	${RM} -rf ${WRKSRC}/docs/man
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${WWWDIR} "! -name *.orig")

.include <bsd.port.mk>

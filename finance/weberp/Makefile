# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	weberp
PORTVERSION=	4.08.4
CATEGORIES=	finance www
MASTER_SITES=	SF/web-erp/
DISTNAME=	webERP${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	An Open-Source Web-Based ERP System

PORTSCOUT=	skipv:3.12

USES=		gettext zip
USE_PHP=	mysql gettext
WRKSRC=		${WRKDIR}/webERP${PORTVERSION}

NO_BUILD=	yes
SUB_FILES=	pkg-message

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}
	@${CHMOD} -R 755 ${STAGEDIR}${WWWDIR}

post-install:
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} 755 -R ${WWWDIR}' \
		>> ${TMPPLIST}

.include <bsd.port.mk>

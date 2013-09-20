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

USE_ZIP=	yes
USE_PHP=	mysql gettext
USES=		gettext
WRKSRC=		${WRKDIR}/webERP${PORTVERSION}

NO_BUILD=	yes
SUB_FILES=	pkg-message

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHMOD} -R 755 ${WWWDIR}

post-install:
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} 755 -R ${WWWDIR}' \
		>> ${TMPPLIST}

	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

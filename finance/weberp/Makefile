# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	weberp
PORTVERSION=	4.12.3
PORTREVISION=	2
CATEGORIES=	finance www
MASTER_SITES=	SF/web-erp/
DISTNAME=	webERP_${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Open-Source Web-Based ERP System

LICENSE=	GPLv2

BROKEN_powerpc64=	Does not build

PORTSCOUT=	skipv:3.12

USES=		gettext shebangfix zip
SHEBANG_FILES=	report_runner.php
USE_PHP=	mysqli gettext
WRKSRC=		${WRKDIR}/webERP

NO_BUILD=	yes
SUB_FILES=	pkg-message
PLIST=		${WRKDIR}/plist
ERPDIR=		www/weberp

pre-install:
	@${ECHO_CMD} -e '@owner ${WWWOWN}\n@group ${WWWGRP}' > ${PLIST}
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?${ERPDIR}?g" >> ${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s?${WRKSRC}?@dir ${ERPDIR}?g" >> ${PLIST}
	@${ECHO_CMD} -e '@owner root\n@group wheel' >> ${PLIST}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	@${CHMOD} -R 755 ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>

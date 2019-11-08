# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	weberp
PORTVERSION=	4.15.1
CATEGORIES=	finance www
MASTER_SITES=	SF/web-erp/
DISTNAME=	webERP_${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Open-Source Web-Based ERP System

LICENSE=	GPLv2

PORTSCOUT=	skipv:3.12

USES=		gettext php shebangfix zip
SHEBANG_FILES=	report_runner.php \
		build/make_release.sh \
		build/check_syntax.sh
USE_PHP=	mysqli gettext
WRKSRC=		${WRKDIR}/webERP-${PORTVERSION}

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

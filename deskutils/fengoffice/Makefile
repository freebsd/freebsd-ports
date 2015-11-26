# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fengoffice
PORTVERSION=	2.3.2.1
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	SF/opengoo/${PORTNAME}/${PORTNAME}_${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Open source web-based collaboration software

DEPRECATED=	PHP 5.4 EOL reached
EXPIRATION_DATE=	2016-01-15

USES=		zip
NO_BUILD=	yes
USE_PHP=	mysql gd simplexml
DEFAULT_PHP_VER=5
WANT_PHP_WEB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST=		${WRKDIR}/pkg-plist
SUB_FILES=	pkg-message
EXTRACT_AFTER_ARGS=	-d ${WRKSRC}

FENGOFFICE_DIR=		www/${PORTNAME}
FENGOFFICE_WWWDIR=	${PREFIX}/${FENGOFFICE_DIR}

OPTIONS_DEFINE=	DOCS

pre-extract:
	@${MKDIR} ${WRKDIR}/${PORTNAME}

post-extract:
	@${MKDIR} ${WRKDIR}/${PORTNAME}-docs
	@${MV} ${WRKSRC}/readme.txt ${WRKDIR}/${PORTNAME}-docs/README

pre-install:
	@${RM} -f ${PLIST}
	@${ECHO_CMD} -e '@owner ${WWWOWN}\n@group ${WWWGRP}' >> ${PLIST}
	@cd ${WRKSRC} && \
		${FIND} . -type f | ${SORT} | ${SED} -e 's|^|www/fengoffice/|' -e 's|\./||g' >> ${PLIST} && \
			${FIND} . -type d | ${SORT} -r | ${SED} -e 's|^|@dir www/fengoffice|' -e 's|\.||g' >> ${PLIST}
	@${ECHO_CMD} -e '@owner root\n@group wheel' >> ${PLIST}
	@${ECHO_CMD} "%%PORTDOCS%%%%DOCSDIR%%/README" >> ${PLIST}

do-install:
	@${MKDIR} ${STAGEDIR}${FENGOFFICE_WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${FENGOFFICE_WWWDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-docs/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fengoffice
PORTVERSION=	2.3.2.1
CATEGORIES=	deskutils
MASTER_SITES=	SF/opengoo/${PORTNAME}/${PORTNAME}_${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	An open source web-based collaboration software

USES=		zip:infozip
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

NO_STAGE=	yes
pre-extract:
	@${MKDIR} ${WRKDIR}/${PORTNAME}

post-extract:
	@${MKDIR} ${WRKDIR}/${PORTNAME}-docs
	@${MV} ${WRKSRC}/readme.txt ${WRKDIR}/${PORTNAME}-docs/README

pre-install:
	@${RM} -f ${PLIST}

	@cd ${WRKSRC} && \
		${FIND} . -type f | ${SORT} | ${SED} -e 's|^|www/fengoffice/|' -e 's|\./||g' >> ${PLIST} && \
			${FIND} . -type d | ${SORT} -r | ${SED} -e 's|^|@dirrm www/fengoffice|' -e 's|\.||g' >> ${PLIST}

.	if !defined(NOPORTDOCS)
		@${ECHO_CMD} "%%PORTDOCS%%%%DOCSDIR%%/README" >> ${PLIST}
		@${ECHO_CMD} "%%PORTDOCS%%@dirrm %%DOCSDIR%%" >> ${PLIST}
.	endif

do-install:
	@${MKDIR} ${FENGOFFICE_WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${FENGOFFICE_WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${FENGOFFICE_WWWDIR}
.if !defined (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-docs/README ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

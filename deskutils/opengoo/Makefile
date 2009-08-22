# New ports collection makefile for:	opengoo
# Date created:		2009-08-19
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	opengoo
PORTVERSION=	1.5.2
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}_${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	An open source web office

USE_ZIP=	yes
NO_BUILD=	yes
USE_PHP=	mysql gd simplexml
DEFAULT_PHP_VER=5
IGNORE_WITH_PHP=4
WANT_PHP_WEB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
SUB_FILES=	pkg-message

OPENGOO_DIR=	www/${PORTNAME}
OPENGOO_WWWDIR=	${PREFIX}/${OPENGOO_DIR}

post-extract:
	@${MKDIR} ${WRKDIR}/${PORTNAME}-docs
	@${MV} ${WRKSRC}/readme.txt ${WRKDIR}/${PORTNAME}-docs/README
	@${RM} ${WRKSRC}/.project ${WRKSRC}/license.txt

do-install:
	@${MKDIR} ${OPENGOO_WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${OPENGOO_WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${OPENGOO_WWWDIR}
.if !defined (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-docs/README ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

# New ports collection makefile for:	tvbrowser
# Date Created:				24 May 2005
# Whom:					Lars Engels <lars.engels@0x20.net>
#
# $FreeBSD$
#

PORTNAME=	tvbrowser
PORTVERSION=	2.2.1
CATEGORIES=	german java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	tvbrowser

MAINTAINER=	lars.engels@0x20.net
COMMENT=	A digital tv guide

USE_X_PREFIX=	yes
USE_LDCONFIG=	yes
NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
SUB_FILES=	tvbrowser

DESKTOP_ENTRIES="TV-Browser" \
		"Browse TV programs" \
		"${DATADIR}/imgs/tvbrowser128.png" \
		"tvbrowser" \
		"Application;TV;" \
		false

do-install:
	cd ${WRKSRC} && ${FIND} . -type d -exec ${MKDIR} "${DATADIR}/{}" \;
	cd ${WRKSRC} && ${FIND} . -type f -exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;
	${INSTALL_SCRIPT} ${WRKDIR}/tvbrowser ${PREFIX}/bin

.include <bsd.port.mk>

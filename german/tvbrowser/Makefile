# New ports collection makefile for:	tvbrowser
# Date Created:				24 May 2005
# Whom:					Lars Engels <lars.engels@0x20.net>
#
# $FreeBSD$
#

PORTNAME=	tvbrowser
PORTVERSION=	2.1
CATEGORIES=	german java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	tvbrowser

MAINTAINER=	lars.engels@0x20.net
COMMENT=	A digital tv guide

NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+

do-install:
	@${MKDIR} ${PREFIX}/share/${PORTNAME}
	@${CP} -r ${WRKSRC}/* ${PREFIX}/share/${PORTNAME}
	@${CP} -r ${FILESDIR}/tvbrowser /${PREFIX}/bin/
	@${CHMOD} 755 /${PREFIX}/bin/tvbrowser

.include <bsd.port.mk>

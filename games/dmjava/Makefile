# New ports collection makefile for:	dmjava
# Date Created:		1 Sep 2002
# Whom:			Oliver Lehmann <lehmann@ans-netz.de>
#
# $FreeBSD$
#

PORTNAME=	dmjava
PORTVERSION=	1.05
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://chaos.zpc.cz/files/
MASTER_SITE_SUBDIR=	oliver
DISTNAME=	dmj${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Dungeon Master Java is a remake of the classic Dungeon Master by FTL

EXTRACT_AFTER_ARGS=	-d ${WRKSRC}

USE_ZIP=	yes
USE_JAVA=	1.4+
NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/${PORTNAME}
	@${CP} -r ${WRKSRC}/* ${PREFIX}/${PORTNAME}
	@${ECHO_MSG} ""
	@${ECHO_MSG} "To start dmjava, type 'cd ${PREFIX}/${PORTNAME} && javavm dmnew'"
	@${ECHO_MSG} ""
.include <bsd.port.mk>

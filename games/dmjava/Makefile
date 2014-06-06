# Created by: Oliver Lehmann <lehmann@ans-netz.de>
# $FreeBSD$

PORTNAME=	dmjava
PORTVERSION=	1.05
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://chaos.zpc.cz/files/
MASTER_SITE_SUBDIR=	oliver
DISTNAME=	dmj${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Dungeon Master Java is a remake of the classic Dungeon Master by FTL

EXTRACT_AFTER_ARGS=	-d ${WRKSRC}

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

NO_STAGE=	yes
do-install:
	@${MKDIR} ${PREFIX}/${PORTNAME}
	@${CP} -r ${WRKSRC}/* ${PREFIX}/${PORTNAME}
	@${ECHO_MSG} ""
	@${ECHO_MSG} "To start dmjava, type 'cd ${PREFIX}/${PORTNAME} && javavm dmnew'"
	@${ECHO_MSG} ""
.include <bsd.port.mk>

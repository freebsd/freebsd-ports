# Created by: Terry (tabmow@freenode.net)
# $FreeBSD$

PORTNAME=	qwebirc
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	irc www
MASTER_SITES=	https://bitbucket.org/slug/qwebirc/get/
DISTNAME=	stable
EXTRACT_SUFX=	.gz

MAINTAINER=	tabmow@freenode.net
COMMENT=	Fast, easy to use, free, and open source web IRC client

USES=		twisted:run,conch,mail,names,web,words
WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
USE_PYTHON=	yes
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/${PORTNAME}
	(cd ${WRKDIR}/${PORTNAME} && \
	${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/www/${PORTNAME} )

post-install:
	${MV} ${STAGEDIR}${PREFIX}/www/${PORTNAME}/config.py.example \
		${STAGEDIR}${PREFIX}/www/${PORTNAME}/config.py.sample

.include <bsd.port.mk>

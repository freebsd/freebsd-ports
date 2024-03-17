PORTNAME=	pircbot
PORTVERSION=	1.5.0
PORTREVISION=	1
CATEGORIES=	irc java
MASTER_SITES=	http://www.jibble.org/files/ \
		http://www.i-scream.org/pub/www.jibble.org/files/

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	PircBot Java IRC Bot Framework
WWW=		http://www.jibble.org/pircbot.php

LICENSE=	GPLv2

DEPRECATED=	Abandoned upstream, last release in 2009 and superseded by pircbotx (fork)
EXPIRATION_DATE=2024-03-31

USES=		zip
NO_BUILD=	yes
NO_ARCH=	yes
USE_JAVA=	yes

SUB_FILES=	pkg-message
SUB_LIST=	JAVAJARDIR=${JAVAJARDIR}

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_DATA} ${WRKSRC}/pircbot.jar ${STAGEDIR}${JAVAJARDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -r ${WRKSRC}/javadocs/* ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>

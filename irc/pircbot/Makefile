PORTNAME=	pircbot
PORTVERSION=	1.5.0
PORTREVISION=	1
CATEGORIES=	irc java
MASTER_SITES=	http://www.jibble.org/files/ \
		http://www.i-scream.org/pub/www.jibble.org/files/

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	PircBot Java IRC Bot Framework

LICENSE=	GPLv2

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

# Created by: Nicola Vitale	<nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mkgichessclub
PORTVERSION=	2.2.0
#PORTREVISION=	0
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	MKGIChessClub-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Chess playing server with a pure web interface

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

IGNORE_WITH_PHP=	71 72 73

OPTIONS_DEFINE=	GNUCHESS PHALANX DOCS
GNUCHESS_DESC=	Install gnuchess robot
PHALANX_DESC=	Install phalanx robot

OPTIONS_DEFAULT=	GNUCHESS PHALANX

NO_BUILD=	yes

SUB_FILES=	pkg-message

USES=		python
USE_MYSQL=	server
USE_PHP=	mysql pcre session
GNUCHESS_RUN_DEPENDS=	gnuchess:games/gnuchess
PHALANX_RUN_DEPENDS=	phalanx:games/phalanx

WRKSRC=	${WRKDIR}/MKGIChessClub-${PORTVERSION}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}; cd ${WRKSRC}; \
	${INSTALL_DATA} database/* ${STAGEDIR}${DATADIR}; \
	${MKDIR} ${STAGEDIR}${WWWDIR}; cd www; ${CP} -R . ${STAGEDIR}${WWWDIR}

	${MKDIR} ${STAGEDIR}${DOCSDIR}; \
	${INSTALL_DATA} ${WRKSRC}/README.INSTALL ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

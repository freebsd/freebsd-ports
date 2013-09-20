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

OPTIONS_DEFINE=	GNUCHESS PHALANX
GNUCHESS_DESC=	Install gnuchess robot
PHALANX_DESC=	Install phalanx robot

OPTIONS_DEFAULT=	GNUCHESS PHALANX

NO_BUILD=	yes

SUB_FILES=	pkg-message

USE_MYSQL=	server
USE_PHP=	mysql pcre session
USE_PYTHON=	yes

WRKSRC=	${WRKDIR}/MKGIChessClub-${PORTVERSION}

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${MKDIR} ${DATADIR}; cd ${WRKSRC}; \
	${INSTALL_DATA} database/* ${DATADIR}; \
	${MKDIR} ${WWWDIR}; cd www; ${CP} -R . ${WWWDIR}

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}; \
	${INSTALL_DATA} ${WRKSRC}/README.INSTALL ${DOCSDIR}
.endif

# pkg-message taken from www/b2evolution
post-install:
	${CAT} ${PKGMESSAGE}

.if ${PORT_OPTIONS:MGNUCHESS}
RUN_DEPENDS+=	gnuchess:${PORTSDIR}/games/gnuchess
.endif

.if ${PORT_OPTIONS:MPHALANX}
RUN_DEPENDS+=	phalanx:${PORTSDIR}/games/phalanx
.endif

.include <bsd.port.mk>

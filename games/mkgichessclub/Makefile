# New ports collection makefile for:	mkgichessclub
# Date created:		2008-01-11
# Whom:			Nicola Vitale	<nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mkgichessclub
PORTVERSION=	2.2.0
#PORTREVISION=	0
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	MKGIChessClub-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A chess playing server with a pure web interface

OPTIONS=	GNUCHESS "Install gnuchess robot" on \
		PHALANX	"Install phalanx robot" on

NO_BUILD=	yes

SUB_FILES=	pkg-message

USE_MYSQL=	server
USE_PHP=	mysql pcre session
USE_PYTHON=	yes

WRKSRC=	${WRKDIR}/MKGIChessClub-${PORTVERSION}

do-install:
	${MKDIR} ${DATADIR}; cd ${WRKSRC}; \
	${INSTALL_DATA} database/* ${DATADIR}; \
	${MKDIR} ${WWWDIR}; cd www; ${CP} -R . ${WWWDIR}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}; \
	${INSTALL_DATA} ${WRKSRC}/README.INSTALL ${DOCSDIR}
.endif

# pkg-message taken from www/b2evolution
post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if defined (WITH_GNUCHESS)
RUN_DEPENDS+=	gnuchess:${PORTSDIR}/games/gnuchess
.endif

.if defined (WITH_PHALANX)
RUN_DEPENDS+=	phalanx:${PORTSDIR}/games/phalanx
.endif

.include <bsd.port.post.mk>

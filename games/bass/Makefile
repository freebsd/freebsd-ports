# Created by: Alex Trull <freebsd.alex@trull.org>
# $FreeBSD$

PORTNAME=	bass
PORTVERSION=	1.2
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/scummvm/extras/Beneath%20a%20Steel%20Sky
DISTNAME=	bass-cd-1.2

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Beneath a Steel Sky: a post-apocalyptic futuristic graphical adventure

LICENSE=	unknown
LICENSE_NAME=	no name
LICENSE_FILE=	${WRKSRC}/readme.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	scummvm:games/scummvm

USES=		zip
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sky.dnr ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sky.dsk ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sky.cpt ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

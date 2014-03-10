# Created by: Alex Trull <freebsd.alex@trull.org>
# $FreeBSD$

PORTNAME=	fotaq
PORTVERSION=	1.1
CATEGORIES=	games
MASTER_SITES=	SF/scummvm/extras/Flight%20of%20the%20Amazon%20Queen
DISTNAME=	FOTAQ_Talkie-${PORTVERSION}

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Flight of the Amazon Queen: a classic graphical adventure

RUN_DEPENDS=	scummvm:${PORTSDIR}/games/scummvm

USES=		zip
NO_BUILD=	yes

SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/${DISTNAME}
PKGMESSAGE=	${WRKDIR}/pkg-message

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${_DISTDIR}/${EXTRACT_ONLY}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/queen.1c ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

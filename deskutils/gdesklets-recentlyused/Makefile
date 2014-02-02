# $FreeBSD$

PORTNAME=	recentlyused
PORTVERSION=	0.6
PORTREVISION=	12
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.gdesklets.info/archive/
PKGNAMEPREFIX=	gdesklets-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Toolbar for the most recently used items from ~/.recently-used

RUN_DEPENDS=	gdesklets:${PORTSDIR}/deskutils/gdesklets

WRKSRC=		${WRKDIR}/${NAME}

NO_BUILD=	yes
USE_PYTHON=	yes

SUB_FILES=	pkg-message

DATADIR=	${PREFIX}/share/gdesklets
NAME=		RecentlyUsed

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/Displays/${NAME}
	${INSTALL_DATA} ${WRKSRC}/*.display ${STAGEDIR}${DATADIR}/Displays/${NAME}
	@${MKDIR} ${STAGEDIR}${DATADIR}/Sensors/${NAME}
	${INSTALL_DATA} ${WRKSRC}/Sensors/${NAME}/*.py ${STAGEDIR}${DATADIR}/Sensors/${NAME}
	${INSTALL_DATA} ${WRKSRC}/Sensors/${NAME}/AUTHORS ${STAGEDIR}${DATADIR}/Sensors/${NAME}
	@${CP} ${WRKSRC}/Sensors/${NAME}/.recently-used ${STAGEDIR}${DATADIR}/Sensors/${NAME}

.include <bsd.port.mk>

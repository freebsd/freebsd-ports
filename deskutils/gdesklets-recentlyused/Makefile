# $FreeBSD$

PORTNAME=	recentlyused
PORTVERSION=	0.6
PORTREVISION=	12
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.gdesklets.info/archive/
PKGNAMEPREFIX=	gdesklets-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A toolbar for the most recently used items from ~/.recently-used

RUN_DEPENDS=	gdesklets:${PORTSDIR}/deskutils/gdesklets

WRKSRC=		${WRKDIR}/${NAME}

NO_BUILD=	yes
USE_PYTHON=	yes

SUB_FILES=	pkg-message

DATADIR=	${PREFIX}/share/gdesklets
NAME=		RecentlyUsed

do-install:
	@${MKDIR} ${DATADIR}/Displays/${NAME}
	${INSTALL_DATA} ${WRKSRC}/*.display ${DATADIR}/Displays/${NAME}
	@${MKDIR} ${DATADIR}/Sensors/${NAME}
	${INSTALL_DATA} ${WRKSRC}/Sensors/${NAME}/*.py ${DATADIR}/Sensors/${NAME}
	${INSTALL_DATA} ${WRKSRC}/Sensors/${NAME}/AUTHORS ${DATADIR}/Sensors/${NAME}
	@${CP} ${WRKSRC}/Sensors/${NAME}/.recently-used ${DATADIR}/Sensors/${NAME}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

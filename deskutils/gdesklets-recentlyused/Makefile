# New ports collection makefile for:	gdesklets-recentlyused
# Date created:				02 September 2003
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	recentlyused
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
PKGNAMEPREFIX= gdesklets-
DISTNAME=	recently-used-${PORTVERSION}

MAINTAINER=	mezz7@cox.net
COMMENT=	A toolbar for the most recently used items from ~/.recently-used

RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/gdesklets-core.pc:${PORTSDIR}/deskutils/gdesklets

USE_X_PREFIX=	yes
NAME=		RecentlyUsed
DATADIR=	${PREFIX}/share/gnome

do-build:
	@${WRKSRC}/Install_${NAME}_Sensor.bin --nomsg ${WRKSRC}
	@${FIND} ${WRKSRC} -name '*.orig' -delete

do-install:
	@${MKDIR} ${DATADIR}/gdesklets/Displays/${NAME}
	@${MKDIR} ${DATADIR}/gdesklets/Sensors/${NAME}
	@${INSTALL_DATA} ${WRKSRC}/*.display ${DATADIR}/gdesklets/Displays/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/${NAME}/*.py ${DATADIR}/gdesklets/Sensors/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/${NAME}/AUTHORS ${DATADIR}/gdesklets/Sensors/${NAME}/
	@${CP} ${WRKSRC}/${NAME}/.recently-used ${DATADIR}/gdesklets/Sensors/${NAME}/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

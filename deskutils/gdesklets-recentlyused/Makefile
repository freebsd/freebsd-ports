# New ports collection makefile for:	gdesklets-recentlyused
# Date created:				02 September 2003
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	gdesklets-recentlyused
PORTVERSION=	0.6
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
DISTNAME=	recently-used-${PORTVERSION}

MAINTAINER=	mezz7@cox.net
COMMENT=	A toolbar for the most recently used items from ~/.recently-used

RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/gdesklets-core.pc:${PORTSDIR}/deskutils/gdesklets

USE_X_PREFIX=	yes
NAME=		RecentlyUsed

do-build:
	@${WRKSRC}/Install_${NAME}_Sensor.bin --nomsg ${WRKSRC}
	@${FIND} ${WRKSRC} -name '*.orig' -delete

do-install:
	@${MKDIR} ${PREFIX}/share/gnome/gdesklets/Displays/${NAME}
	@${CP} ${WRKSRC}/*.display ${PREFIX}/share/gnome/gdesklets/Displays/${NAME}/
	@${CP} -Rp ${WRKSRC}/${NAME} ${PREFIX}/share/gnome/gdesklets/Sensors/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

# New ports collection makefile for:	gdesklets-gnomebar
# Date created:		2004-06-24
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	gnomebar
PORTVERSION=	0.20
PORTREVISION=	2
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
PKGNAMEPREFIX=	gdesklets-
DISTNAME=	GnomeBar-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A lightweight replacement for the gnome panel

RUN_DEPENDS=	${X11BASE}/share/gnome/gdesklets/Sensors/IconButton/__init__.py:${PORTSDIR}/deskutils/gdesklets-sensor-psi_iconbutton

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_REINPlACE=	yes
NO_BUILD=	yes

DATADIR=	${PREFIX}/share/gnome
NAME=		GnomeBar
PKGMESSAGE=	${WRKDIR}/pkg-message

post-patch:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|; s|%%NAME%%|${NAME}|' \
		${FILESDIR}/pkg-message.in >${PKGMESSAGE}

do-install:
	@${MKDIR} ${DATADIR}/gdesklets/Displays/${NAME}/gfx
	@${CP} -Rf ${WRKSRC}/ ${DATADIR}/gdesklets/Displays/${NAME}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

# New ports collection makefile for:	gdesklets-starterbar
# Date created:				02 September 2003
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	gdesklets-starterbar
PORTVERSION=	0.20
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
DISTNAME=	starterbar-desklet-${PORTVERSION}

MAINTAINER=	mezz7@cox.net
COMMENT=	An icon bar for GNOME 2.x where you can put starters into

RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/gdesklets-core.pc:${PORTSDIR}/deskutils/gdesklets

USE_BZIP2=	yes
USE_X_PREFIX=	yes
NAME=		StarterBar

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		"Requires FreeBSD 5.0 or later, because of uuidgen command first appeared in FreeBSD 5.0"
.endif

do-build:
	@${WRKSRC}/Install_${NAME}_Sensor.bin --nomsg ${WRKSRC}
	@${PATCH} ${WRKSRC}/${NAME}/Icon.py < ${FILESDIR}/${NAME}::Icon.py
	@${PATCH} ${WRKSRC}/${NAME}/__init__.py < ${FILESDIR}/${NAME}::__init__.py
	@${FIND} ${WRKSRC} -name '*.orig' -delete

do-install:
	@${MKDIR} ${PREFIX}/share/gnome/gdesklets/Displays/${NAME}
	@${CP} ${WRKSRC}/*.display ${PREFIX}/share/gnome/gdesklets/Displays/${NAME}/
	@${CP} -Rp ${WRKSRC}/gfx ${PREFIX}/share/gnome/gdesklets/Displays/${NAME}/
	@${CP} -Rp ${WRKSRC}/${NAME} ${PREFIX}/share/gnome/gdesklets/Sensors/
	@${CP} ${WRKSRC}/README ${PREFIX}/share/gnome/gdesklets/Displays/${NAME}/
	@${LN} -s ${PREFIX}/share/gnome/gdesklets/Displays/${NAME}/README \
		${PREFIX}/share/gnome/gdesklets/Sensors/${NAME}/README

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

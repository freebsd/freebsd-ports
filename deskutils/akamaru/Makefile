# Created by: Phillip Neumann <pneumann@gmail.com>
# $FreeBSD$

PORTNAME=	akamaru
PORTVERSION=	0.1
PORTREVISION=	10
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://people.freedesktop.org/~krh/
DISTNAME=	${PORTNAME}

MAINTAINER=	pneumann@gmail.com
COMMENT=	Simple, but fun, physics engine prototype

RUN_DEPENDS=	xcompmgr:${PORTSDIR}/x11-wm/xcompmgr

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26
USES=		gmake pkgconfig
USE_GNOME=	gconf2 gtk20
GCONF_SCHEMAS=	kiba.schemas
SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} \
		-e '/^CFLAGS =/s|-g| ${CFLAGS} |' \
		-e '/^CPPFLAGS =/s|$$| ${CPPFLAGS}|' \
		-e '/^LDFLAGS =/s|-g| ${LDFLAGS} |' \
		-e '/^LDLIBS =/s|$$| ${LIBS} -lm|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' \
	    	${WRKSRC}/populate-dock.sh

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/dock ${STAGEDIR}${PREFIX}/bin/kiba-dock
	@${INSTALL_PROGRAM} ${WRKSRC}/akamaru ${STAGEDIR}${PREFIX}/bin/akamaru
	@${MKDIR} ${STAGEDIR}${LOCALBASE}/etc/gconf/schemas
	@${INSTALL_DATA} ${WRKSRC}/kiba.schemas ${STAGEDIR}${LOCALBASE}/etc/gconf/schemas
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/populate-dock.sh ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>

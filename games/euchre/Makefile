# Created by: Frank Laszlo <laszlof@freebsdmatrix.net>
# $FreeBSD$

PORTNAME=	euchre
PORTVERSION=	0.8
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Very popular card game with variable skill levels

LICENSE=	GPLv2 # (or later)

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules

PLIST_FILES=	bin/euchre

DESKTOP_ENTRIES="Euchre" "" "" "${PORTNAME}" "" true

post-patch:
	@${REINPLACE_CMD} -e \
		'/^AM_/s|-Werror||' ${WRKSRC}/configure

.include <bsd.port.mk>

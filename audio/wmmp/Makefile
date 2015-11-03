# Created by: Peter Vereshagin <peter@vereshagin.org>
# $FreeBSD$

PORTNAME=	WMmp
PORTVERSION=	0.10.0
PORTREVISION=	1
CATEGORIES=	audio windowmaker
MASTER_SITES=	SF/musicpd/${PORTNAME}/${PORTVERSION}

MAINTAINER=	peter@vereshagin.org
COMMENT=	Window Maker Dockapp for MusicPD

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26
GNU_CONFIGURE=	yes
USE_XORG=	x11 xpm

PLIST_FILES=	"@(,kmem,2555) bin/WMmp" \
		man/man1/WMmp.1.gz

post-patch:
	@${REINPLACE_CMD} '/SETGID_FLAGS=/d' ${WRKSRC}/configure

.include <bsd.port.mk>

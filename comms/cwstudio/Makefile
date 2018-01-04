# $FreeBSD$

PORTNAME=	cwstudio
DISTVERSION=	0.9.6
CATEGORIES=	comms hamradio
MASTER_SITES=	SOURCEFORGE/cwstudio

MAINTAINER=	luqqe@users.sourceforge.net
COMMENT=	Multichannel portable Morse code signals generator

LICENSE=	GPLv3+

USES+=		ncurses
USE_WX=		3.0+

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx-config=${LOCALBASE}/bin/wxgtk2u-3.0-config

PLIST_FILES=	bin/cwcli \
		bin/cwcurses \
		bin/cwwx \
		man/man1/cwstudio.1.gz \

.include <bsd.port.mk>

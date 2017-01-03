# $FreeBSD$

PORTNAME=	cwstudio
PORTVERSION=	0.9.5
CATEGORIES=	comms hamradio
MASTER_SITES=	SOURCEFORGE/cwstudio

MAINTAINER=	luqqe@users.sourceforge.net
COMMENT=	Fast, portable and lightweight Morse code signals generator

LICENSE=	GPLv3+

USE_WX=		3.0+
USES+=		ncurses

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx-config=${LOCALBASE}/bin/wxgtk2u-3.0-config

PLIST_FILES=	bin/cwcli \
		bin/cwcurses \
		bin/cwwx \
		man/man1/cwstudio.1.gz \

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	lxmusic
PORTVERSION=	0.4.5
CATEGORIES=	audio
MASTER_SITES=	SF/ghostbsdproject/package/LXMusic/

MAINTAINER=	ericturgeon@ghostbsd.org
COMMENT=	LXDE music player based on xmms2

LIB_DEPENDS=	xmmsclient:${PORTSDIR}/audio/xmms2 \
		notify:${PORTSDIR}/devel/libnotify

USE_GNOME=	gtk20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

post-install:
	@-${LOCALBASE}/bin/update-desktop-database > /dev/null

.include <bsd.port.mk>

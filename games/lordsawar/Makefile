PORTNAME=	lordsawar
PORTVERSION=	0.3.2
CATEGORIES=	games
MASTER_SITES=	SAVANNAH

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Warlords II clone

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lib gettext gmake gnome libarchive pkgconfig \
		shebangfix
USE_GNOME=	gtkmm30 intltool libxslt
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
SHEBANG_FILES=	create-lw-file
bash_CMD=	/bin/sh

OPTIONS_DEFINE=	SOUND
OPTIONS_DEFAULT=SOUND

SOUND_USE=	GSTREAMER1=mm,good,ogg,vorbis
SOUND_CONFIGURE_ENABLE=	sound

post-patch:
	@${REINPLACE_CMD} -e 's|class SetList<T>::|typename SetList<T>::|' \
		${WRKSRC}/src/setlist.h

.include <bsd.port.mk>

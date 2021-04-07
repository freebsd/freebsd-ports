PORTNAME=	wavbreaker
PORTVERSION=	0.13
CATEGORIES=	audio

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	GUI tool to split WAV and MP3 files

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libao.so:audio/libao

USES=		desktop-file-utils gettext-tools gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo gtk30
GH_ACCOUNT=	thp
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	MOODBAR MPG123
OPTIONS_DEFAULT=MOODBAR MPG123

MOODBAR_DESC=		Visual representation from .mood files
MOODBAR_RUN_DEPENDS=	moodbar:audio/moodbar
MOODBAR_MESON_TRUE=	moodbar

MPG123_LIB_DEPENDS=	libmpg123.so:audio/mpg123
MPG123_MESON_TRUE=	mp3

.include <bsd.port.mk>

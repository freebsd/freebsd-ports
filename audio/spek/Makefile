PORTNAME=	spek
DISTVERSION=	0.8.5
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	https://github.com/alexkay/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	alexander@kojevnikov.com
COMMENT=	Acoustic spectrum analyser
WWW=		http://spek.cc/

LICENSE=	GPLv3+

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

USES=		compiler:c++11-lib desktop-file-utils gmake gnome \
		localbase:ldflags pkgconfig tar:xz
USE_GNOME=	intltool
USE_WX=		3.2+
WX_CONF_ARGS=	absolute
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>

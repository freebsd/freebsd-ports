PORTNAME=	cyanrip
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
CATEGORIES=	audio

MAINTAINER=	daniel.engberg.lists@pyret.net
COMMENT=	Audio CD ripper with command-line interface and focus on accuracy

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libcdio.so:sysutils/libcdio \
		libcdio_paranoia.so:sysutils/libcdio-paranoia \
		libcurl.so:ftp/curl \
		libmusicbrainz5.so:audio/libmusicbrainz5

USES=		compiler:c11 localbase meson pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	cyanreg

PLIST_FILES=	bin/cyanrip

.include <bsd.port.mk>

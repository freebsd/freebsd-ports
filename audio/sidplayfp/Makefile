PORTNAME=	sidplayfp
PORTVERSION=	2.5.0
DISTVERSIONPREFIX=	v
CATEGORIES=	audio

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Console SID/MUS player using sidplayfp
WWW=		https://github.com/libsidplayfp/sidplayfp

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libpulse.so:audio/pulseaudio \
		libstilview.so:audio/libsidplayfp

USES=		autoreconf gettext iconv localbase:ldflags pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	libsidplayfp
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/sidplayfp \
		bin/stilview \
		man/man1/sidplayfp.1.gz \
		man/man1/stilview.1.gz \
		man/man5/sidplayfp.ini.5.gz

OPTIONS_DEFINE=		OUT123
OPTIONS_DEFAULT=	OUT123

OUT123_DESC=	Build with out123 library

OUT123_LIB_DEPENDS=	libout123.so:audio/mpg123
OUT123_CONFIGURE_WITH=	out123

.include <bsd.port.mk>

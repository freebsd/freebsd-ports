PORTNAME=	ncpamixer
DISTVERSION=	1.3.7
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Ncurses PulseAudio mixer
WWW=		https://github.com/fulhax/ncpamixer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE

LIB_DEPENDS=	libpulse.so:audio/pulseaudio

USES=		cmake compiler:c++17-lang ncurses

USE_GITHUB=	yes
GH_ACCOUNT=	fulhax

CMAKE_OFF=	BUILD_MANPAGES

WRKSRC_SUBDIR=	src

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>

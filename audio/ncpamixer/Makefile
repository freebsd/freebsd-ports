# $FreeBSD$

PORTNAME=	ncpamixer
DISTVERSION=	1.3.3.1
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Ncurses PulseAudio mixer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE

LIB_DEPENDS=	libpulse.so:audio/pulseaudio

USES=		cmake compiler:c++17-lang ncurses:port

USE_GITHUB=	yes
GH_ACCOUNT=	fulhax

WRKSRC_SUBDIR=	src

CFLAGS+=	-I${LOCALBASE}/include/ncurses # USES=ncurses:port fails to add this

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>

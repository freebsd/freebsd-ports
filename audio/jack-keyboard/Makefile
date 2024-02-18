PORTNAME=	jack-keyboard
DISTVERSION=	2.7.2
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SF \
		http://home.selasky.org:8192/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Virtual keyboard for JACK MIDI
WWW=		https://jack-keyboard.sourceforge.net/

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libjack.so:audio/jack

USE_GNOME=	gtk20
USES=		cmake gnome

OPTIONS_DEFINE=		LASH
OPTIONS_DEFAULT=	LASH

LASH_LIB_DEPENDS=	liblash.so:audio/lash
LASH_CMAKE_ON=	-DLashEnable:BOOL=On
LASH_CMAKE_OFF=	-DLashEnable:BOOL=Off

post-patch:
	${REINPLACE_CMD} -e 's|DESTINATION man/man1|DESTINATION share/man/man1|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>

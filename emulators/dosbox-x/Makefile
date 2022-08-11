PORTNAME=	dosbox-x
DISTVERSIONPREFIX=	${PORTNAME}-v
DISTVERSION=	0.84.1
CATEGORIES=	emulators

MAINTAINER=	nc@FreeBSD.org
COMMENT=	DOSBox fork

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png

USES=		autoreconf iconv sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-core-inline
USE_SDL=	net sdl sound

USE_GITHUB=	yes
GH_ACCOUNT=	joncampbell123

OPTIONS_DEFINE=		DOCS
OPTIONS_RADIO=		DEBUGGER
OPTIONS_RADIO_DEBUGGER=	DEBUGGER_ENABLE DEBUGGER_HEAVY
DEBUGGER_ENABLE_DESC=	Enable internal debugger
DEBUGGER_HEAVY_DESC=	Enable internal debugger with extra features

DEBUGGER_ENABLE_CONFIGURE_ON=	--enable-debug=yes
DEBUGGER_HEAVY_CONFIGURE_ON=	--enable-debug=heavy

.include <bsd.port.mk>

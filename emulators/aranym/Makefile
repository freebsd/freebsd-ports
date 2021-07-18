PORTNAME=	aranym
DISTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}/
DISTNAME=	${PORTNAME}_${DISTVERSION}.orig

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Atari Running on Any Machine

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	openjpeg>0:graphics/openjpeg \
		sdl-config:devel/sdl12
RUN_DEPENDS=	bash:shells/bash

USES=		gmake perl5 pkgconfig gl localbase:ldflags sdl shebangfix xorg
USE_GL=		gl
USE_SDL=	sdl2 image2
USE_XORG=	x11

SHEBANG_FILES=	tools/arabridge

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	-disable-nat-debug --disable-nat-debug --enable-nfjpeg

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

.include <bsd.port.mk>

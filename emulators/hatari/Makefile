# Created by: Michael Neumann <mneumann@ntecs.de>
# $FreeBSD$

PORTNAME=	hatari
PORTVERSION=	2.2.1
CATEGORIES=	emulators
MASTER_SITES=	http://download.tuxfamily.org/hatari/${PORTVERSION}/

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Atari ST emulator

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/gpl.txt

BROKEN_armv6=		fails to configure: CMake Error: Generator: execution of make failed

LIB_DEPENDS=	libportaudio.so:audio/portaudio \
		libpng.so:graphics/png

USES=		cmake desktop-file-utils gnome python:3.6+ readline \
		sdl shared-mime-info shebangfix tar:bzip2 xorg
USE_GNOME=	gtk30
USE_XORG=	sm ice x11 xext
USE_PYTHON=	concurrent

SHEBANG_FILES=	python-ui/*.py tools/*.py \
		tools/debugger/*.py tools/hconsole/*.py

CMAKE_ARGS=	-DETCDIR:PATH="${PREFIX}/etc" \
		-DMANDIR:PATH="man/man1" \
		-DREADLINE_FOUND:BOOL=ON

INSTALLS_ICONS=	yes

OPTIONS_DEFINE=		DEBUG DOCS SDL2 WINUAE

DEBUG_CFLAGS_OFF=	-DNDEBUG
SDL2_DESC=		Use SDL2 libraries instead of SDL 1.2
SDL2_USES=		iconv
SDL2_USE=		sdl=sdl2
SDL2_USE_OFF=		sdl=sdl
SDL2_CMAKE_BOOL=	ENABLE_SDL2
SDL2_CFLAGS=		-I${ICONV_INCLUDE_PATH}
WINUAE_DESC=		Build with WinUAE CPU core
WINUAE_CMAKE_BOOL=	ENABLE_WINUAE_CPU

post-patch:
.for i in doc/*.1 python-ui/*.1 tools/*.1 tools/debugger/*.1 tools/hconsole/*.1 tools/hmsa/*.1
	@${REINPLACE_CMD} -e \
		's|^/etc/hatari.cfg .*|${PREFIX}/etc/hatari.cfg| ; \
		 s|/usr/share|${PREFIX}/share|' ${WRKSRC}/${i}
.endfor
	@${REINPLACE_CMD} -e \
		's|-Wno-maybe-uninitialized||' ${WRKSRC}/src/cpu/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		's|%%PYTHON_CMD%%|${PYTHON_CMD}| ; \
		 s|%%PYTHON_VERSION%%|${PYTHON_VERSION}|' ${WRKSRC}/tools/atari-hd-image.sh

post-install:
	${MKDIR} ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/python-ui/*.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/tools/*.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/tools/debugger/*.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/tools/hconsole/*.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/tools/hmsa/*.1 ${STAGEDIR}${MANPREFIX}/man/man1

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

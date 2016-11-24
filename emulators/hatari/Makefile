# Created by: Michael Neumann <mneumann@ntecs.de>
# $FreeBSD$

PORTNAME=	hatari
PORTVERSION=	1.9.0
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://download.tuxfamily.org/hatari/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Atari ST emulator

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/gpl.txt

LIB_DEPENDS=	libportaudio.so:audio/portaudio \
		libpng.so:graphics/png
BUILD_DEPENDS=	python:lang/python
RUN_DEPENDS=	python:lang/python

USES=		cmake desktop-file-utils python readline shared-mime-info \
		shebangfix tar:bzip2
SHEBANG_FILES=	tools/atari-convert-dir.py
python_OLD_CMD=	/usr/bin/python2
USE_GNOME=	pygtk2
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
SDL2_CMAKE_ON=		-DENABLE_SDL2:BOOL=ON
SDL2_CFLAGS=		-I${ICONV_INCLUDE_PATH}
WINUAE_DESC=		Build with WinUAE CPU core (experimental)
WINUAE_CMAKE_ON=	-DENABLE_WINUAE_CPU:BOOL=ON

post-patch:
.for i in doc/hatari.1 doc/fr/hatari.1 tools/hconsole/hconsole.1
	@${REINPLACE_CMD} -e \
		's|^/etc/hatari.cfg .*|${PREFIX}/etc/hatari.cfg| ; \
		 s|/usr/share|${PREFIX}/share|' ${WRKSRC}/${i}
.endfor
	@${REINPLACE_CMD} -e \
		's|-Wno-maybe-uninitialized||' ${WRKSRC}/src/cpu/CMakeLists.txt

post-install:
	@${MKDIR} ${STAGEDIR}${MANPREFIX}/man/fr/man1
	${INSTALL_MAN} ${WRKSRC}/doc/fr/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/fr/man1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/fr
	${INSTALL_DATA} ${WRKSRC}/doc/fr/*.txt ${STAGEDIR}${DOCSDIR}/fr

.include <bsd.port.mk>

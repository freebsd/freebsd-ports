PORTNAME=	hatari
PORTVERSION=	2.5.0
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://download.tuxfamily.org/hatari/${PORTVERSION}/

MAINTAINER=	laurent.chardon@gmail.com
COMMENT=	Atari ST emulator
WWW=		https://hatari.tuxfamily.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/gpl.txt

BROKEN_armv6=	fails to configure: CMake Error: Generator: execution of make failed

LIB_DEPENDS=	libpng.so:graphics/png \
		libudev.so:devel/libudev-devd \
		libreadline.so:devel/readline \
		libcapstone.so:devel/capstone

USES=		cmake desktop-file-utils gnome python readline \
		sdl shared-mime-info shebangfix tar:bzip2 xorg iconv
USE_GNOME=	gtk30 pygobject3
USE_XORG=	sm ice x11 xext
USE_SDL=	sdl2

SHEBANG_FILES=	python-ui/*.py tools/*.py \
		tools/debugger/*.py tools/hconsole/*.py

CMAKE_ARGS=	-DETCDIR:PATH="${PREFIX}/etc"

OPTIONS_DEFINE=		DEBUG DOCS DSP TRACE SMALL
OPTIONS_DEFAULT=	DOCS DSP TRACE

DEBUG_DESC=		Build with debug information
DOCS_DESC=		Install extra documentation
DSP_DESC=		DSP 56k emulator for Falcon mode
TRACE_DESC=		Tracing messages for debugging
SMALL_DESC=		Use less memory at the expense of emulation speed

DSP_CMAKE_BOOL=		ENABLE_DSP_EMU
TRACE_CMAKE_BOOL=	ENABLE_TRACING
SMALL_CMAKE_BOOL=	ENABLE_SMALL_MEM

TEST_TARGET=	test

.include <bsd.port.options.mk>

# CMAKE_ARGS CMAKE_BUILD_TYPE is getting overriden
.if ${PORT_OPTIONS:MDEBUG}
CMAKE_BUILD_TYPE=Debug
INSTALL_TARGET=install
.else
CMAKE_BUILD_TYPE=Release
.endif

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
	${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/python-ui/*.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/tools/*.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/tools/debugger/*.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/tools/hconsole/*.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/tools/hmsa/*.1 ${STAGEDIR}${PREFIX}/share/man/man1

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

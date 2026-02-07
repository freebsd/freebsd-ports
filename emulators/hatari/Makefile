PORTNAME=	hatari
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.1
CATEGORIES=	emulators

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

USES=		cmake desktop-file-utils gnome localbase python readline sdl \
		shared-mime-info shebangfix tar:bzip2 xorg

USE_GITLAB=	yes
GL_SITE=	https://framagit.org/

USE_GNOME=	gtk30 pygobject3
USE_SDL=	sdl2
USE_XORG=	ice sm x11 xext

SHEBANG_FILES=	python-ui/*.py tools/*.py \
		tools/debugger/*.py tools/hconsole/*.py

CMAKE_ARGS=	-DETCDIR:PATH="${PREFIX}/etc"

TEST_TARGET=	test

OPTIONS_DEFINE=		DEBUG DOCS DSP SMALL TRACE
OPTIONS_DEFAULT=	DOCS DSP TRACE

DEBUG_DESC=		Build with debug information
DOCS_DESC=		Install extra documentation
DSP_DESC=		DSP 56k emulator for Falcon mode
SMALL_DESC=		Use less memory at the expense of emulation speed
TRACE_DESC=		Tracing messages for debugging

DSP_CMAKE_BOOL=		ENABLE_DSP_EMU
SMALL_CMAKE_BOOL=	ENABLE_SMALL_MEM
TRACE_CMAKE_BOOL=	ENABLE_TRACING

.include <bsd.port.options.mk>

# CMAKE_ARGS CMAKE_BUILD_TYPE is getting overriden
.if ${PORT_OPTIONS:MDEBUG}
CMAKE_BUILD_TYPE=	Debug
INSTALL_TARGET=		install
.else
CMAKE_BUILD_TYPE=	Release
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|^/etc/hatari.cfg .*|${PREFIX}/etc/hatari.cfg| ; \
		 s|/usr/share|${PREFIX}/share|' \
		${WRKSRC}/doc/*.1 \
		${WRKSRC}/python-ui/*.1 \
		${WRKSRC}/tools/*.1 \
		${WRKSRC}/tools/debugger/*.1 \
		${WRKSRC}/tools/hconsole/*.1 \
		${WRKSRC}/tools/hmsa/*.1
	@${REINPLACE_CMD} -e \
		's|-Wno-maybe-uninitialized||' ${WRKSRC}/src/cpu/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		's|%%PYTHON_CMD%%|${PYTHON_CMD}| ; \
		 s|%%PYTHON_VERSION%%|${PYTHON_VERSION}|' ${WRKSRC}/tools/atari-hd-image.sh

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN}	${WRKSRC}/doc/*.1 \
			${WRKSRC}/python-ui/*.1 \
			${WRKSRC}/tools/*.1 \
			${WRKSRC}/tools/debugger/*.1 \
			${WRKSRC}/tools/hconsole/*.1 \
			${WRKSRC}/tools/hmsa/*.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

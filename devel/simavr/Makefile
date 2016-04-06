# Created by: Felix Palmen <felix@palmen-it.de>
# $FreeBSD$

PORTNAME=	simavr
PORTVERSION=	1.3
CATEGORIES=	devel

PATCH_DIST_STRIP=	-p1

MAINTAINER=	felix@palmen-it.de
COMMENT=	Simulator for several Atmel AVR chips

LICENSE=	GPLv3

BUILD_DEPENDS=	avr-gcc:devel/avr-gcc \
		bash:shells/bash \
		${LOCALBASE}/avr/lib/libc.a:devel/avr-libc

USE_GITHUB=	yes
GH_ACCOUNT=	buserror
GH_TAGNAME=	v${PORTVERSION}

USES=		gmake pkgconfig
ALL_TARGET=	build-simavr
MAKE_ARGS=	"RELEASE=1 PREFIX=${PREFIX} DESTDIR=${STAGEDIR}${PREFIX}"

USE_LDCONFIG=	yes

OPTIONS_DEFINE=		DOCS EXAMPLES THREADSAFE
THREADSAFE_DESC=	Add a patch to make debugging output thread-safe

DOCS_ALL_TARGET=	doc
DOCS_USE=		tex=latex:build tex=pdftex:build tex=texmf:build

EXAMPLES_ALL_TARGET=	build-examples
EXAMPLES_USE=		xorg=xdamage xorg=xcb xorg=xext xorg=xfixes \
			xorg=xrandr gl=glut

THREADSAFE_PATCH_SITES=	https://github.com/zirias/simavr/commit/
THREADSAFE_PATCHFILES=	4b7c8c5245e1bbb8cac04948564622f47178b5f0.diff

AVR_STRIP_CMD?=	avr-strip
DUMPMACHINE=	${CC} -dumpmachine
OBJDIRNAME=	obj-$$(${DUMPMACHINE})

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/simavr
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsimavr.so.1

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/manual/manual.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/simavr_callgraph.pdf ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
.for BOARDELF in hd77480,charlcd i2ctest ledramp simduino ssd1306,ssd1306demo timer_64led
	BOARDELF=${BOARDELF}; \
	BOARD=$${BOARDELF%%,*}; \
	ELF=$${BOARDELF##*,}; \
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/board_$${BOARD}; \
	${INSTALL_PROGRAM} \
		${WRKSRC}/examples/board_$${BOARD}/${OBJDIRNAME}/$${ELF}.elf \
		${STAGEDIR}${EXAMPLESDIR}/board_$${BOARD}/$${ELF}; \
	${INSTALL_DATA} ${WRKSRC}/examples/board_$${BOARD}/*.[aihc]* \
			${WRKSRC}/examples/board_$${BOARD}/README \
			${WRKSRC}/examples/board_$${BOARD}/Makefile \
			${STAGEDIR}${EXAMPLESDIR}/board_$${BOARD}/
.endfor
.for AXF in \
		hd77480/atmega48_charlcd \
		i2ctest/atmega1280_i2ctest \
		ledramp/atmega48_ledramp \
		ssd1306/atmega32_ssd1306 \
		timer_64led/atmega168_timer_64led
	${AVR_STRIP_CMD} ${STAGEDIR}${EXAMPLESDIR}/board_${AXF}.axf
.endfor
.for EXDIR in parts shared
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/${EXDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/${EXDIR}/*.[hc] \
			${STAGEDIR}${EXAMPLESDIR}/${EXDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/Makefile.common ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/Makefile ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/Makefile.opengl \
			${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

# Created by: Felix Palmen <felix@palmen-it.de>
# $FreeBSD$

PORTNAME=	simavr
PORTVERSION=	1.6
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel emulators
DIST_SUBDIR=	${PORTNAME}

PATCH_DIST_STRIP=	-p1
PATCH_SITES=	https://github.com/buserror/simavr/commit/
PATCHFILES=	86264ad6d0b6b921130e293769d8ebaec512eecd.diff \
		e5ea627259daae64ddbe67402b6d121e0143cd21.diff \
		082939e64e1632d8ea0b1d6ebea93ca832c9e762.diff

MAINTAINER=	felix@palmen-it.de
COMMENT=	Simulator for several Atmel AVR chips

LICENSE=	GPLv3

BUILD_DEPENDS=	avr-gcc:devel/avr-gcc \
		bash:shells/bash \
		${LOCALBASE}/avr/lib/libc.a:devel/avr-libc

USES=		compiler:c11 gl gmake pathfix pkgconfig xorg
USE_GL=	gl glu glut
PATHFIX_MAKEFILEIN=	Makefile
USE_XORG=	xdamage xcb xext xfixes xrandr
USE_GITHUB=	yes
GH_ACCOUNT=	buserror
USE_LDCONFIG=	yes

ALL_TARGET=	build-parts
MAKE_ARGS=	"RELEASE=1 PREFIX=${PREFIX} DESTDIR=${STAGEDIR}${PREFIX}"

OPTIONS_DEFINE=		DOCS EXAMPLES

DOCS_ALL_TARGET=	doc
DOCS_USE=		tex=latex:build tex=pdftex:build tex=texmf:build

AVR_STRIP_CMD?=	avr-strip
DUMPMACHINE=	${CC} -dumpmachine
OBJDIRNAME=	obj-$$(${DUMPMACHINE})

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/simavr
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsimavr.so.1
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsimavrparts.so.1

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/manual/manual.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/simavr_callgraph.pdf ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
.for BOARDELF in ds1338,ds1338demo hd44780,charlcd i2ctest ledramp simduino ssd1306,ssd1306demo timer_64led
	BOARDELF=${BOARDELF}; \
	BOARD=$${BOARDELF%%,*}; \
	ELF=$${BOARDELF##*,}; \
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/board_$${BOARD}; \
	${INSTALL_PROGRAM} \
		${WRKSRC}/examples/board_$${BOARD}/${OBJDIRNAME}/$${ELF}.elf \
		${STAGEDIR}${EXAMPLESDIR}/board_$${BOARD}/$${ELF}; \
	${INSTALL_DATA} ${WRKSRC}/examples/board_$${BOARD}/*.[aihc]* \
			${WRKSRC}/examples/board_$${BOARD}/Makefile \
			${STAGEDIR}${EXAMPLESDIR}/board_$${BOARD}/;\
	${TEST} -f ${WRKSRC}/examples/board_$${BOARD}/README && \
	${INSTALL_DATA} ${WRKSRC}/examples/board_$${BOARD}/README \
			${STAGEDIR}${EXAMPLESDIR}/board_$${BOARD}/ || ${TRUE}
.endfor
.for AXF in \
		ds1338/atmega32_ds1338 \
		hd44780/atmega48_charlcd \
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

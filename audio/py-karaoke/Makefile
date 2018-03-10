# Created by: Elias Mandouvalos <ocean@mail.gr>
# $FreeBSD$

PORTNAME=	karaoke
PORTVERSION=	0.7.5
PORTREVISION=	15
CATEGORIES=	audio python
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python karaoke application (Plays CD+G, MP3+G, OGG+G files)

LICENSE=	LGPL21+

BUILD_DEPENDS=	${PYGAME} \
		${LOCALBASE}/libdata/pkgconfig/pthread-stubs.pc:devel/libpthread-stubs
LIB_DEPENDS=	libaa.so:graphics/aalib
RUN_DEPENDS=	dejavu>0:x11-fonts/dejavu \
		${PYGAME} \
		${PYNUMPY}

USES=		compiler:c++11-lib desktop-file-utils iconv python:2.7 shebangfix zip
SHEBANG_FILES=	install/pykaraoke_mini install/pykar install/pykaraoke \
		install/pycdg install/pympg
USE_SDL=	sdl
USE_XORG=	x11 xau xcb xdmcp
USE_WX=		3.0+
WX_COMPS=	python:lib

USE_PYTHON=	distutils autoplist

DATADIR=	${PREFIX}/share/py${PORTNAME}

PLIST_FILES=	${BIN_SCRIPTS:S,^,bin/,} \
		${DATA_FONTS:S,^,%%DATADIR%%/fonts/,}

OPTIONS_DEFINE=		MUTAGEN

MUTAGEN_DESC=		Mutagen support
MUTAGEN_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mutagen>0:audio/py-mutagen@${FLAVOR}

BIN_SCRIPTS=	cdg2mpg pycdg pykar pykaraoke pykaraoke_mini pympg
DATA_FONTS=	DejaVuSans.ttf DejaVuSansCondensed.ttf \
		DejaVuSansCondensed-Bold.ttf

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${CHOSEN_COMPILER_TYPE} == gcc
MAKE_ENV+=	LD_LIBRARY_PATH="${LOCALBASE}/lib/${CC}:$$LD_LIBRARY_PATH"
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/setup.cfg
	@${REINPLACE_CMD} -e \
		'/if /s|==|=|' ${WRKSRC}/install/cdg2mpg
.for i in pykaraoke.desktop pykaraoke_mini.desktop
	@${REINPLACE_CMD} -e \
		'/^Encodings=/d ; \
		 /^Icon=/s|/usr/share/pykaraoke|${DATADIR}| ; \
		 /^MimeType=/s|audio/midi$$|audio/midi;| ; \
		 /^Categories=/s|Application;||' ${WRKSRC}/install/${i}
.endfor

post-build:
	@${MKDIR} ${WRKDIR}/wrappers
.for i in ${BIN_SCRIPTS}
	@${ECHO_CMD} -n \
		>> ${WRKDIR}/wrappers/${i}
	@${ECHO_CMD} '#!/bin/sh' \
		>> ${WRKDIR}/wrappers/${i}
.if ${OPSYS} == FreeBSD && ${CHOSEN_COMPILER_TYPE} == gcc
	@${ECHO_CMD} 'LD_LIBRARY_PATH="${LOCALBASE}/lib/${CC}:$$LD_LIBRARY_PATH"' \
		>> ${WRKDIR}/wrappers/${i}
	@${ECHO_CMD} 'export LD_LIBRARY_PATH' \
		>> ${WRKDIR}/wrappers/${i}
	@${ECHO_CMD} \
		>> ${WRKDIR}/wrappers/${i}
.endif
	@${ECHO_CMD} 'exec ${PREFIX}/libexec/${i} "$$@"' \
		>> ${WRKDIR}/wrappers/${i}
.endfor

post-install:
.for i in ${BIN_SCRIPTS}
	(cd ${WRKDIR}/wrappers && ${INSTALL_SCRIPT} ${i} \
		${STAGEDIR}${PREFIX}/bin)
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}/fonts
.for i in ${DATA_FONTS}
	@${LN} -sf ${LOCALBASE}/share/fonts/dejavu/${i} \
		${STAGEDIR}${DATADIR}/fonts
.endfor
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_pycdgAux.so

.include <bsd.port.post.mk>

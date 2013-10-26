# Created by: Elias Mandouvalos <ocean@mail.gr>
# $FreeBSD$

PORTNAME=	karaoke
PORTVERSION=	0.7.5
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python karaoke application (Plays CD+G, MP3+G, OGG+G files)

LICENSE=	LGPL21 # (or later)

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}game>0:${PORTSDIR}/devel/py-game
LIB_DEPENDS=	pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		aa:${PORTSDIR}/graphics/aalib
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}game>0:${PORTSDIR}/devel/py-game \
		dejavu>0:${PORTSDIR}/x11-fonts/dejavu \
		${PYNUMPY}

OPTIONS_DEFINE=	MUTAGEN
MUTAGEN_DESC=	Enable Mutagen support

USES=		iconv
NO_STAGE=	yes
USE_ZIP=	yes
USE_SDL=	sdl
USE_XORG=	x11 xau xcb xdmcp
USE_WX=		2.6+
WX_COMPS=	python:lib

USE_PYTHON=		-2.7
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	py${PORTNAME}

DATADIR=	${PREFIX}/share/py${PORTNAME}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMUTAGEN}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}mutagen>0:${PORTSDIR}/audio/py-mutagen
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

post-install:
	@${MKDIR} ${DATADIR}/fonts
.for i in DejaVuSans.ttf DejaVuSansCondensed-Bold.ttf DejaVuSansCondensed.ttf
	@${LN} -sf ${LOCALBASE}/lib/X11/fonts/dejavu/${i} ${DATADIR}/fonts
.endfor

.include <bsd.port.mk>

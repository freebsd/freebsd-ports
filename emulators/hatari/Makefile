# Created by: Michael Neumann <mneumann@ntecs.de>
# $FreeBSD$

PORTNAME=	hatari
PORTVERSION=	1.8.0
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://download.tuxfamily.org/hatari/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Atari ST emulator

LICENSE=	GPLv2 # (or later)

BUILD_DEPENDS=	portaudio2>0:${PORTSDIR}/audio/portaudio2
LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png
RUN_DEPENDS=	portaudio2>0:${PORTSDIR}/audio/portaudio2

USES=		cmake readline tar:bzip2
USE_GNOME=	pygtk2
USE_SDL=	sdl
CMAKE_ARGS=	-DPORTAUDIO_INCLUDE_DIR:STRING="${PA2_INCLUDE_DIR}" \
		-DPORTAUDIO_LIBRARY:STRING="${PA2_LIBRARY}" \
		-DCMAKE_C_FLAGS_RELEASE:STRING="-DNDEBUG" \
		-DETCDIR:STRING="${PREFIX}/etc" \
		-DMANDIR:STRING="man/man1"

OPTIONS_DEFINE=	DOCS

PA2_INCLUDE_DIR=${LOCALBASE}/include/portaudio2
PA2_LIBRARY=	${LOCALBASE}/lib/portaudio2/libportaudio.so

post-patch:
.for i in doc/hatari.1 doc/fr/hatari.1 tools/hconsole/hconsole.1
	@${REINPLACE_CMD} -e \
		's|^/etc/hatari.cfg .*|${PREFIX}/etc/hatari.cfg| ; \
		 s|/usr/share|${PREFIX}/share|' ${WRKSRC}/${i}
.endfor
	@${REINPLACE_CMD} -e '/DESTINATION/s|/icons/.*)|/pixmaps)|' \
		${WRKSRC}/python-ui/CMakeLists.txt

post-build:
	@cd ${WRKSRC}/doc/fr && ${GZIP_CMD} -c ${PORTNAME}.1 > ${PORTNAME}.1.gz

post-install:
	@${MKDIR} ${STAGEDIR}${MANPREFIX}/man/fr/man1
	(cd ${WRKSRC}/doc/fr && ${INSTALL_MAN} ${PORTNAME}.1.gz \
		${STAGEDIR}${MANPREFIX}/man/fr/man1)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/fr
	(cd ${WRKSRC}/doc/fr && ${INSTALL_DATA} *.txt \
		${STAGEDIR}${DOCSDIR}/fr)

.include <bsd.port.mk>

# Created by: Michael Neumann <mneumann@ntecs.de>
# $FreeBSD$

PORTNAME=	hatari
PORTVERSION=	1.7.0
CATEGORIES=	emulators
MASTER_SITES=	http://download.tuxfamily.org/hatari/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Atari ST emulator

LICENSE=	GPLv2

BUILD_DEPENDS=	portaudio2>=0:${PORTSDIR}/audio/portaudio2
LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png
RUN_DEPENDS=	portaudio2>=0:${PORTSDIR}/audio/portaudio2

OPTIONS_DEFINE=	DOCS

USE_BZIP2=	yes
USES=		cmake readline
USE_GNOME=	pygtk2
USE_SDL=	sdl
CMAKE_ARGS=	-DPORTAUDIO_INCLUDE_DIR:STRING="${PA2_INCLUDE_DIR}" \
		-DPORTAUDIO_LIBRARY:STRING="${PA2_LIBRARY}" \
		-DCMAKE_C_FLAGS_RELEASE:STRING="-DNDEBUG" \
		-DETCDIR:STRING="${PREFIX}/etc" \
		-DMANDIR:STRING="man/man1"

CFLAGS+=	-I${LOCALBASE}/include/portaudio2
PA2_INCLUDE_DIR=-I${LOCALBASE}/include/portaudio2
PA2_LIBRARY=	${LOCALBASE}/lib/portaudio2/libportaudio.so

PORTDOCS=	*

post-patch:
.for file in doc/hatari.1 doc/fr/hatari.1 tools/hconsole/hconsole.1
	@${REINPLACE_CMD} -e \
		's|^/etc/hatari.cfg .*|${PREFIX}/etc/hatari.cfg| ; \
		 s|/usr/share|${PREFIX}/share|' ${WRKSRC}/${file}
.endfor
	@${REINPLACE_CMD} -e '/doc/s|^add_|#add_|' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e '/DESTINATION/s|/icons/.*)|/pixmaps)|' \
		${WRKSRC}/python-ui/CMakeLists.txt

post-build:
	@cd ${WRKSRC}/doc && ${GZIP_CMD} -c ${PORTNAME}.1 > ${PORTNAME}.1.gz
	@cd ${WRKSRC}/doc/fr && ${GZIP_CMD} -c ${PORTNAME}.1 > ${PORTNAME}.1.gz

post-install:
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} ${PORTNAME}.1.gz \
		${STAGEDIR}${MANPREFIX}/man/man1)
	@${MKDIR} ${STAGEDIR}${MANPREFIX}/man/fr/man1
	(cd ${WRKSRC}/doc/fr && ${INSTALL_MAN} ${PORTNAME}.1.gz \
		${STAGEDIR}${MANPREFIX}/man/fr/man1)

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} readme.txt ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} *.html [a-z]*.txt ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/fr
	(cd ${WRKSRC}/doc/fr && ${INSTALL_DATA} *.txt ${STAGEDIR}${DOCSDIR}/fr)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/images
	(cd ${WRKSRC}/doc/images && ${INSTALL_DATA} *.png ${STAGEDIR}${DOCSDIR}/images)

.include <bsd.port.mk>

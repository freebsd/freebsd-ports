# New ports collection makefile for:    hatari
# Date created:         15 March 2004
# Whom:                 Michael Neumann <mneumann@ntecs.de>
#
# $FreeBSD$
#

PORTNAME=	hatari
PORTVERSION=	1.4.0
CATEGORIES=	emulators
MASTER_SITES=	BERLIOS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Atari ST emulator

BUILD_DEPENDS=	portaudio>=19:${PORTSDIR}/audio/portaudio2
LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png
RUN_DEPENDS=	portaudio>=19:${PORTSDIR}/audio/portaudio2

USE_BZIP2=	yes
USE_GNOME=	pygtk2
USE_SDL=	sdl
USE_CMAKE=	yes
CMAKE_ARGS=	-DPORTAUDIO_INCLUDE_DIR:STRING="${PA2_INCLUDE_DIR}" \
		-DPORTAUDIO_LIBRARY:STRING="${PA2_LIBRARY}" \
		-DCMAKE_C_FLAGS_RELEASE:STRING="-DNDEBUG"

MANCOMPRESSED=	yes
MANLANG=	"" fr
MAN1=		${PORTNAME}.1
MAN1_EN=	${PORTNAME}ui.1

CFLAGS+=	-I${LOCALBASE}/include/portaudio2
PA2_INCLUDE_DIR=-I${LOCALBASE}/include/portaudio2
PA2_LIBRARY=	${LOCALBASE}/lib/portaudio2/libportaudio.so

post-extract:
	@cd ${WRKSRC}/doc && ${GZIP_CMD} -c ${PORTNAME}.1 > ${PORTNAME}.1.gz
	@cd ${WRKSRC}/doc/fr && ${GZIP_CMD} -c ${PORTNAME}.1 > ${PORTNAME}.1.gz

post-patch:
	@${REINPLACE_CMD} -e '/CONFDIR/s|"/etc|"${PREFIX}/etc| ; \
		 /MANDIR/s|share/man|man| ; \
		 /doc/s|^add_|#add_|' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e '/DESTINATION/s|/icons/.*)|/pixmaps)|' \
		${WRKSRC}/python-ui/CMakeLists.txt

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1.gz ${MANPREFIX}/man/man1
	@${MKDIR} ${MANPREFIX}/man/fr/man1
	${INSTALL_MAN} ${WRKSRC}/doc/fr/${PORTNAME}.1.gz ${MANPREFIX}/man/fr/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/[a-z]*.txt ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/fr
	${INSTALL_DATA} ${WRKSRC}/doc/fr/*.txt ${DOCSDIR}/fr
	@${MKDIR} ${DOCSDIR}/images
	${INSTALL_DATA} ${WRKSRC}/doc/images/*.png ${DOCSDIR}/images
.endif

.include <bsd.port.mk>

# Created by: Michael Neumann <mneumann@ntecs.de>
# $FreeBSD$

PORTNAME=	hatari
PORTVERSION=	1.8.0
PORTREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	http://download.tuxfamily.org/hatari/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Atari ST emulator

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/gpl.txt

LIB_DEPENDS=	libportaudio.so:${PORTSDIR}/audio/portaudio \
		libpng.so:${PORTSDIR}/graphics/png

USES=		cmake readline tar:bzip2
USE_GNOME=	pygtk2
USE_SDL=	sdl
CMAKE_ARGS=	-DCMAKE_C_FLAGS_RELEASE:STRING="-DNDEBUG" \
		-DETCDIR:STRING="${PREFIX}/etc" \
		-DMANDIR:STRING="man/man1"

OPTIONS_DEFINE=	DOCS

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
	${INSTALL_MAN} ${WRKSRC}/doc/fr/${PORTNAME}.1.gz ${STAGEDIR}${MANPREFIX}/man/fr/man1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/fr
	${INSTALL_DATA} ${WRKSRC}/doc/fr/*.txt ${STAGEDIR}${DOCSDIR}/fr

.include <bsd.port.mk>

PORTNAME=		praat
DISTVERSIONPREFIX=	v
DISTVERSION=		6.4.37
CATEGORIES=		audio science

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Speech analysis tool used for doing phonetics by computer
WWW=		https://www.fon.hum.uva.nl/praat/ \
		https://github.com/praat/praat/

LICENSE=	GPLv3+

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libharfbuzz.so:print/harfbuzz
# These are recommended but I can't tell the difference
RUN_DEPENDS=	Charis>=0:x11-fonts/charis \
		DoulosSIL>=0:x11-fonts/doulos

USES=		compiler:c++17-lang gnome iconv pkgconfig xorg
USE_GITHUB=	yes
USE_GNOME=	cairo gdkpixbuf gtk30
USE_XORG=	x11

PLIST_FILES=	bin/praat \
		share/man/man1/praat.1.gz \
		share/applications/${PORTNAME}.desktop \
		share/icons/hicolor/scalable/apps/${PORTNAME}.svg

post-patch:
	${REINPLACE_CMD} -e 's|^CPPFLAGS =|CPPFLAGS +=|' \
		${WRKSRC}/*/Makefile \
		${WRKSRC}/external/*/Makefile
	${CP} ${WRKSRC}/makefiles/makefile.defs.freebsd.alsa \
		${WRKSRC}/makefile.defs
	@${CP} ${WRKSRC}/main/praat-480.svg \
		${WRKSRC}/praat.svg

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/praat ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/praat.1 ${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/main/${PORTNAME}.desktop \
		${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>

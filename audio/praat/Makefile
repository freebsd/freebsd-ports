# $FreeBSD$

PORTNAME=		praat
DISTVERSIONPREFIX=	v
DISTVERSION=		6.1.40
CATEGORIES=		audio science

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Phonetics by Computer

LICENSE=	GPLv2

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libasound.so:audio/alsa-lib
# These are recommended but I can't tell the difference
# RUN_DEPENDS=	CharisSIL>=0:x11-fonts/charis \
#		DoulosSIL>=0:x11-fonts/doulos

USES=		compiler:c++11-lang dos2unix gnome iconv pkgconfig xorg
USE_GNOME=	cairo gdkpixbuf2 gtk30
USE_GITHUB=	yes
USE_XORG=	x11

DOS2UNIX_FILES=	\
		fon/Makefile \
		melder/Makefile \
		sys/Makefile \
		EEG/Makefile

PLIST_FILES=	bin/praat man/man1/praat.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|^CPPFLAGS =|CPPFLAGS +=|' \
		${WRKSRC}/*/Makefile \
		${WRKSRC}/external/*/Makefile
	@${CP} ${WRKSRC}/makefiles/makefile.defs.freebsd.alsa \
		${WRKSRC}/makefile.defs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/praat ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/praat.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=		praat
DISTVERSIONPREFIX=	v
DISTVERSION=		6.1.14
CATEGORIES=		audio science

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Phonetics by Computer

LICENSE=	GPLv2

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libjack.so:audio/jack \
		libasound.so:audio/alsa-lib

USES=		compiler:c++11-lang dos2unix gnome iconv pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk20
USE_GITHUB=	yes

DOS2UNIX_REGEX=	.*Makefile
PLIST_FILES=	bin/praat man/man1/praat.1.gz

HARDCPPFLAGS=	${WRKSRC}/EEG/Makefile \
		${WRKSRC}/FFNet/Makefile \
		${WRKSRC}/LPC/Makefile \
		${WRKSRC}/artsynth/Makefile \
		${WRKSRC}/dwsys/Makefile \
		${WRKSRC}/dwtools/Makefile \
		${WRKSRC}/external/clapack/blas/Makefile \
		${WRKSRC}/external/clapack/lapack/Makefile \
		${WRKSRC}/external/espeak/Makefile \
		${WRKSRC}/external/flac/Makefile \
		${WRKSRC}/external/gsl/Makefile \
		${WRKSRC}/external/mp3/Makefile \
		${WRKSRC}/fon/Makefile \
		${WRKSRC}/gram/Makefile \
		${WRKSRC}/kar/Makefile \
		${WRKSRC}/main/Makefile \
		${WRKSRC}/melder/Makefile \
		${WRKSRC}/stat/Makefile \
		${WRKSRC}/sys/Makefile

post-patch:
	@${REINPLACE_CMD} -e 's|^CPPFLAGS =|CPPFLAGS +=|' ${HARDCPPFLAGS}
	@${CP} ${FILESDIR}/makefile.defs.freebsd.alsa \
		${WRKSRC}/makefile.defs
	@${REINPLACE_CMD} -e 's|%%WRKSRC%%|${WRKSRC}|g' \
			  -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/makefile.defs
	@${REINPLACE_CMD} -e 's| log2| NUMlog2|g' \
			  -e 's|feof (f)|feof (f.get_ptr())|g' \
			  -e 's|ferror (f)|ferror (f.get_ptr())|g' \
		${WRKSRC}/dwtools/Sound_extensions.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/praat ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/praat.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>

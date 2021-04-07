PORTNAME=	ponscripter-sekai
PORTVERSION=	0.0.6
DISTVERSIONPREFIX=	v
PORTREVISION=	7
CATEGORIES=	games

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	101c68e22921.patch:-p1 4fb1180d2b54.patch:-p1 25e752f272d0.patch:-p1

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	NScripter-like novel-game interpreter with Unicode support

LICENSE=	GPLv2+

LIB_DEPENDS=	libsmpeg2.so:multimedia/smpeg2 \
		libfreetype.so:print/freetype2

CONFLICTS=	ponscripter-[0-9]* # doesn't exist yet

USE_GITHUB=	yes
GH_ACCOUNT=	sekaiproject
GH_PROJECT=	${PORTNAME:S/sekai/fork/}

USES=		compiler:c++11-lang gmake sdl shebangfix
USE_SDL=	image2 mixer2
EXTRACT_AFTER_ARGS=--exclude src/extlib
SHEBANG_FILES=	util/xml-template
HAS_CONFIGURE=	yes
# XXX Pretend clang is like lang/gcc and can USE_CPU_GFX
CONFIGURE_ENV=	CC_VER="4.8" CC="${CC} ${CFLAGS}" CXX="${CXX} ${CXXFLAGS}" \
		CPATH="${LOCALBASE}/include" LIBRARY_PATH="${LOCALBASE}/lib"
CONFIGURE_ARGS=	--prefix="${STAGEDIR}${PREFIX}" --unsupported-compiler
LDFLAGS+=	-Wl,--as-needed
PORTDOCS=	BUGS CHANGES MANUAL README TODO
PLIST_FILES=	bin/ponscr \
		share/emacs/site-lisp/ponscripter-mode.el

OPTIONS_DEFINE=	DOCS MANPAGES TREMOR
OPTIONS_DEFAULT=MANPAGES ${MACHINE_CPU:Msoftfp:C/.+/TREMOR/}

MANPAGES_BUILD_DEPENDS=	xmlto:textproc/xmlto
MANPAGES_PLIST_FILES=\
	man/man6/ponscr.6.gz \
	man/man7/ponscr-ext.7.gz \
	man/man7/ponscr-syntax.7.gz \
	man/man7/ponscripter.7.gz

TREMOR_LIB_DEPENDS=	libvorbisidec.so:audio/libtremor
TREMOR_CFLAGS=		-DINTEGER_OGG_VORBIS
TREMOR_LIB_DEPENDS_OFF=	libvorbisfile.so:audio/libvorbis

post-patch:
	@${REINPLACE_CMD} -e '/^ifdef DEBUG/,/^$$/d' \
		-e 's/$$STRIPFLAG/${STRIP}/' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's/$$(LIBS)/$$(LDFLAGS) &/' \
		${WRKSRC}/src/Makefile.ponscripter

post-patch-MANPAGES-off:
	@${REINPLACE_CMD} -i .manpages.bak \
		-e '/install-man/d' \
		-e 's/xmlto/${FALSE}/' \
		${WRKSRC}/configure

post-patch-TREMOR-on:
	@${REINPLACE_CMD} -i .tremor.bak \
		-e 's/"libogg, libvorbis"/libvorbisidec/' \
		-e 's,vorbis/vorbisfile,tremor/ivorbisfile,' \
		-e 's,vorbis/codec,tremor/ivorbiscodec,' \
		-e '/genlink/ { s/vorbisfile/vorbisidec/; \
			/ogg/d; /vorbis$$/d; }' \
		-e 's/ $$LINKogg//; s/ $$LINKvorbis//' \
		-e 's/LINKvorbisfile/LINKvorbisidec/' \
		${WRKSRC}/configure

post-build-MANPAGES-on:
	# Remove extraneous whitespace to unbreak manpage syntax
	${REINPLACE_CMD} -e 's/^[[:space:]]*//; /^$$/d' \
		${WRKSRC}/doc/*.[0-9]

post-install:
	${INSTALL_DATA} ${WRKSRC}/misc/ponscripter-mode.el \
		${STAGEDIR}${PREFIX}/share/emacs/site-lisp

post-install-DOCS-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

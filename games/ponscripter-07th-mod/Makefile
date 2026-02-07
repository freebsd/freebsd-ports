PORTNAME=	ponscripter
DISTVERSIONPREFIX=	v
DISTVERSION=	4.0.1
PORTREVISION=	1
CATEGORIES=	games
PKGNAMESUFFIX=	-${GH_ACCOUNT}

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	69068bf83653.patch:-p1 # https://github.com/sekaiproject/ponscripter-fork/pull/98

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	NScripter-like novel-game interpreter with Unicode support
WWW=		https://github.com/sekaiproject/ponscripter-fork

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsmpeg2.so:multimedia/smpeg2 \
		libfreetype.so:print/freetype2

CONFLICTS=	ponscripter # doesn't exist yet

USE_GITHUB=	yes
GH_ACCOUNT=	07th-mod
GH_PROJECT=	${PORTNAME}-fork

USES=		compiler:c++11-lang gmake pkgconfig sdl shebangfix
USE_CXXSTD=	gnu++98
USE_SDL=	image2 mixer2
EXTRACT_AFTER_ARGS=--exclude src/extlib
SHEBANG_FILES=	util/xml-template
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	CC="${CC} ${CFLAGS}" CXX="${CXX} ${CXXFLAGS}"
CONFIGURE_ARGS=	--prefix="${STAGEDIR}${PREFIX}" --unsupported-compiler
LDFLAGS+=	-Wl,--as-needed
PORTDOCS=	BUGS CHANGES MANUAL README.md TODO
PLIST_FILES=	bin/ponscr \
		share/emacs/site-lisp/ponscripter-mode.el

OPTIONS_DEFINE=	DOCS MANPAGES NOTIFY TREMOR
OPTIONS_DEFAULT=MANPAGES NOTIFY ${MACHINE_CPU:Msoftfp:C/.+/TREMOR/}

MANPAGES_BUILD_DEPENDS=	xmlto:textproc/xmlto
MANPAGES_CONFIGURE_OFF=	--no-docs
MANPAGES_PLIST_FILES=\
	share/man/man6/ponscr.6.gz \
	share/man/man7/ponscr-ext.7.gz \
	share/man/man7/ponscr-syntax.7.gz \
	share/man/man7/ponscripter.7.gz

NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_USES=		gnome
NOTIFY_USE=		GNOME=glib20 # g_object_unref
NOTIFY_CONFIGURE_WITH=	libnotify

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

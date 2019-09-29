# Created by: trevor
# $FreeBSD$

PORTNAME=	denemo
PORTVERSION=	2.0.6
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	GNU

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Graphical score editor

LICENSE=	GPLv3+

BROKEN_armv6=	fails to package: tar: Pathname cannot be converted from UTF-8 to current locale
BROKEN_armv7=	fails to package: tar: Pathname cannot be converted from UTF-8 to current locale
BROKEN_mips=	fails to package: tar: Pathname cannot be converted from UTF-8 to current locale

LIB_DEPENDS=	libaubio.so:audio/aubio \
		libfluidsynth.so:audio/fluidsynth \
		libjack.so:audio/jack \
		libsmf.so:audio/libsmf \
		libsndfile.so:audio/libsndfile \
		libportaudio.so:audio/portaudio \
		librubberband.so:audio/rubberband \
		libguile.so:lang/guile \
		libfftw3.so:math/fftw3
RUN_DEPENDS=	xdg-open:devel/xdg-utils

EXTRACT_BEFORE_ARGS=\
		-s '!\(/Clarinet in B\).*\(\.denemo\)$$!\1b\2!p' -xf

USES=		bison compiler:c++11-lang desktop-file-utils gettext gmake \
		pkgconfig
USE_GNOME=	intltool librsvg2 libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-jack \
		--disable-alsa \
		--disable-portmidi \
		--disable-gtk-doc \
		--disable-gtk-doc-html \
		--disable-gtk-doc-pdf \
		--enable-guile_1_8

CFLAGS+=	-Wno-error=return-type
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		DOCS EXAMPLES LILYPOND PDF
OPTIONS_SINGLE=		TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	GTK2 GTK3
OPTIONS_DEFAULT=	GTK3

GTK2_USE=		gnome=gtk20,gtksourceview2
GTK2_CONFIGURE_ON=	--enable-gtk2
GTK3_USE=		gnome=gtk30,gtksourceview3
LILYPOND_DESC=		Install LilyPond (Printing)
LILYPOND_RUN_DEPENDS=	lilypond:print/lilypond
PDF_CONFIGURE_OFF=	--disable-evince
TOOLKIT_DESC=		GTK+ toolkit

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK3} && ${PORT_OPTIONS:MPDF}
LIB_DEPENDS+=	libevview3.so:graphics/evince
.endif

.if ${PORT_OPTIONS:MGTK2} && ${PORT_OPTIONS:MPDF}
LIB_DEPENDS+=	libatrilview.so:graphics/atril
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lpthread|-pthread| ; \
		 /^CFLAGS=/s|_LIBS|_CFLAGS| ; \
		 s|evince-view-2.30 >= 2.|atril-view-1.5.|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/) install-data-hook/s|^|#|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		 '/^docdir/s|$$(datadir)/$${PACKAGE}|@docdir@|' \
		${WRKSRC}/docs/Makefile.in
	@${REINPLACE_CMD} -e \
		 '/^imagedir/s|$$(datadir)/$${PACKAGE}|@docdir@|' \
		${WRKSRC}/docs/images/Makefile.in
	@${REINPLACE_CMD} -e \
		's|"firefox"|"xdg-open"|' ${WRKSRC}/src/core/prefops.c
.if ${PORT_OPTIONS:MGTK2} && ${PORT_OPTIONS:MPDF}
	@${FIND} ${WRKSRC}/src -name "*.c" | ${XARGS} ${REINPLACE_CMD} -e \
		'/^#include/s|evince|atril|'
.endif

post-install:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "actions templates" \
		${STAGEDIR}${DATADIR})

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in AUTHORS ChangeLog NEWS
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor
.for i in DESIGN DESIGN.lilypond GOALS TODO
	(cd ${WRKSRC}/docs && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${INSTALL_DATA} *.denemo \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>

# Created by: ijliao
# $FreeBSD$

PORTNAME=	images
PORTVERSION=	3.0.2
PORTREVISION=	8
PORTEPOCH=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/cristal/caml-light/bazar-ocaml/ \
		http://caml.inria.fr/distrib/bazar-ocaml/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	camlimages-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	michael.grunewald@laposte.net
COMMENT=	Objective Caml image processing library

BUILD_DEPENDS=	${LOCALBASE}/share/aclocal/ocaml.m4:${PORTSDIR}/lang/ocaml-autoconf

USE_AUTOTOOLS=	aclocal autoheader automake autoconf
ACLOCAL_ARGS=	-I . -I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing
USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAMLFIND_PLIST=	yes
USE_OCAML_WASH=	yes
OCAML_PKGDIRS=	camlimages
USE_OCAML_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include/libpng15
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--without-lablgtk
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	PNG JPEG TIFF XPM GIF FREETYPE GHOSTSCRIPT GTK2 DOCS
OPTIONS_DEFAULT=	PNG JPEG TIFF XPM GIT FREETYPE GHOSTSCRIPT

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png
CONFIGURE_ARGS+=	--with-png
.else
CONFIGURE_ARGS+=	--without-png
.endif

.if ${PORT_OPTIONS:MJPEG}
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
CONFIGURE_ARGS+=	--with-jpeg
.else
CONFIGURE_ARGS+=	--without-jpeg
.endif

.if ${PORT_OPTIONS:MTIFF}
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
CONFIGURE_ARGS+=	--with-tiff
.else
CONFIGURE_ARGS+=	--without-tiff
.endif

.if ${PORT_OPTIONS:MXPM}
USE_XORG=	xpm
CONFIGURE_ARGS+=	--with-xpm
.else
CONFIGURE_ARGS+=	--without-xpm
.endif

.if ${PORT_OPTIONS:MGIF}
LIB_DEPENDS+=	gif.5:${PORTSDIR}/graphics/giflib
CONFIGURE_ARGS+=	--with-gif
.else
CONFIGURE_ARGS+=	--without-gif
.endif

.if ${PORT_OPTIONS:MFREETYPE}
LIB_DEPENDS+=		ttf:${PORTSDIR}/print/freetype
CONFIGURE_ARGS+=	--with-freetype
.else
CONFIGURE_ARGS+=	--without-freetype
.endif

.if ${PORT_OPTIONS:MGHOSTSCRIPT}
USE_GHOSTSCRIPT=	yes
CONFIGURE_ARGS+=	--with-gs
.else
CONFIGURE_ARGS+=	--without-gs
.endif

.if ${PORT_OPTIONS:MGTK2}
CONFIGURE_ARGS+=	--with-lablgtk2
BUILD_DEPENDS+=	lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2
RUN_DEPENDS+=	lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2
.else
CONFIGURE_ARGS+=	--without-lablgtk2
.endif

GNU_CONFIGURE=	yes
#USE_GMAKE=	yes

#the default docsdir gets expanded to ${PREFIX}/share/doc/images
#which isn't of much help when you are searching for the package docs
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
DOCSFILES=	CHANGES README LICENSE

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	${DOCSFILES} doc
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}/doc
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${DOCSDIR}/doc '-name "*.jpg" -o -name "*.html"')
	@${INSTALL_DATA} ${DOCSFILES:S,^,${WRKSRC}/,g} ${DOCSDIR}/
.endif
	@${ECHO_CMD} "lib/ocaml/stublibs/dllcamlimages.so" >> ${TMPPLIST}
	@${ECHO_CMD} "lib/ocaml/stublibs/dllcamlimages_core.so" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${RMDIR} %D/lib/ocaml/stublibs >/dev/null 2>&1 || ${TRUE}" >> ${TMPPLIST}

.include <bsd.port.mk>

# ex:ts=8
# Ports collection makefile for:	ocaml-images
# Date created:			Feb 7, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	images
PORTVERSION=	3.0.2
PORTREVISION=	6
PORTEPOCH=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/cristal/caml-light/bazar-ocaml/ \
		http://caml.inria.fr/distrib/bazar-ocaml/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	camlimages-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Objective Caml image processing library

BUILD_DEPENDS=	${LOCALBASE}/share/aclocal/ocaml.m4:${PORTSDIR}/lang/ocaml-autoconf

USE_AUTOTOOLS=	aclocal:111 autoheader:268 automake:111 autoconf:268
ACLOCAL_ARGS=	-I . -I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing
USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAMLFIND_PLIST=	yes
USE_OCAML_WASH=	yes
OCAML_PKGDIRS=	camlimages
USE_OCAML_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${CPPFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${LDFLAGS}"

OPTIONS=	PNG "Enable PNG support" on \
		JPEG "Enable JPEG support" on \
		TIFF "Enable TIFF support" on \
		XPM "Enable XPM support" on \
		GIF "Enable GIF support" on \
		FREETYPE "Enable text rendering via freetype" on \
		GS "Enable PostScript support via Ghostscript" on \
		GTK1 "Enable LablGTK1 support" off \
		GTK2 "Enable LablGTK2 support (conflicts with LablGTK1)" off

.include <bsd.port.options.mk>

.if !defined(WITHOUT_PNG)
LIB_DEPENDS+=	png.6:${PORTSDIR}/graphics/png
CONFIGURE_ARGS+=	--with-png
.else
CONFIGURE_ARGS+=	--without-png
.endif

.if !defined(WITHOUT_JPEG)
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
CONFIGURE_ARGS+=	--with-jpeg
.else
CONFIGURE_ARGS+=	--without-jpeg
.endif

.if !defined(WITHOUT_TIFF)
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
CONFIGURE_ARGS+=	--with-tiff
.else
CONFIGURE_ARGS+=	--without-tiff
.endif

.if !defined(WITHOUT_XPM)
USE_XORG=	xpm
CONFIGURE_ARGS+=	--with-xpm
.else
CONFIGURE_ARGS+=	--without-xpm
.endif

.if !defined(WITHOUT_GIF)
LIB_DEPENDS+=	ungif.5:${PORTSDIR}/graphics/libungif
CONFIGURE_ARGS+=	--with-gif
.else
CONFIGURE_ARGS+=	--without-gif
.endif

.if !defined(WITHOUT_FREETYPE)
USE_FREETYPE=	yes
CONFIGURE_ARGS+=	--with-freetype
.else
CONFIGURE_ARGS+=	--without-freetype
.endif

.if defined(WITH_GS)
USE_GHOSTSCRIPT=	yes
CONFIGURE_ARGS+=	--with-gs
.else
CONFIGURE_ARGS+=	--without-gs
.endif

.if defined(WITH_GTK1) && defined(WITH_GTK2)
IGNORE=	you should select either LablGTK1 or LablGTK2, but not both
.endif

.if defined(WITH_GTK1)
CONFIGURE_ARGS+=	--with-lablgtk
BUILD_DEPENDS+=	lablgtk:${PORTSDIR}/x11-toolkits/ocaml-lablgtk
RUN_DEPENDS+=	lablgtk:${PORTSDIR}/x11-toolkits/ocaml-lablgtk
.else
CONFIGURE_ARGS+=	--without-lablgtk
.endif

.if defined(WITH_GTK2)
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

.if !defined(NOPORTDOCS)
PORTDOCS=	${DOCSFILES} doc
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/doc
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${DOCSDIR}/doc '-name "*.jpg" -o -name "*.html"')
	@${INSTALL_DATA} ${DOCSFILES:S,^,${WRKSRC}/,g} ${DOCSDIR}/
.endif
	@${ECHO_CMD} "lib/ocaml/stublibs/dllcamlimages.so" >> ${TMPPLIST}
	@${ECHO_CMD} "lib/ocaml/stublibs/dllcamlimages_core.so" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${RMDIR} %D/lib/ocaml/stublibs >/dev/null 2>&1 || ${TRUE}" >> ${TMPPLIST}

.include <bsd.port.mk>

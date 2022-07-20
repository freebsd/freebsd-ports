PORTNAME=	wdune
PORTVERSION=	1.926
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.ourproject.org/pub/wdune/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Graphical VRML97 editor and animation tool

LICENSE=	GPLv2

BUILD_DEPENDS=	cgal>0:math/cgal
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libfreetype.so:print/freetype2 \
		libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libosdCPU.so:graphics/opensubdiv \
		libpng.so:graphics/png \
		libswresample.so:multimedia/ffmpeg

USES=		compiler:c++11-lang gl jpeg motif sdl tar:bzip2 xorg
USE_XORG=	x11 xft xi xmu xext xt
USE_GL=		gl glu glut
USE_SDL=	sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-optimization \
		--without-devil \
		--with-cgalheaders \
		--with-helpurl="${DOCSDIR}/index.html"
CPPFLAGS+=	-I${LOCALBASE}/include/freetype2 -D__FREEBSD__
LDFLAGS+=	-L${LOCALBASE}/lib

CONFLICTS_INSTALL=	ocaml-dune

ALL_TARGET=	dune

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dune ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/bin && ${INSTALL_SCRIPT} dune4kids illegal2vrml \
		${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/man && ${INSTALL_MAN} dune.1 illegal2vrml.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

do-install-DOCS-on:
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

PORTNAME=	wdune
PORTVERSION=	1.956
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.ourproject.org/pub/wdune/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Graphical VRML97 editor and animation tool
WWW=		https://wdune.ourproject.org/

LICENSE=	GPLv2

BUILD_DEPENDS=	cgal>0:math/cgal
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libfreetype.so:print/freetype2 \
		libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libosdCPU.so:graphics/opensubdiv \
		libpng.so:graphics/png \
		libswresample.so.3:multimedia/ffmpeg4

USES=		compiler:c++11-lang gl jpeg localbase:ldflags motif sdl tar:bzip2 xorg
USE_CXXSTD=	c++14
USE_GL=		gl glu glut
USE_SDL=	sdl
USE_XORG=	x11 xft xi xmu xext xt

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-optimization \
		--without-devil \
		--with-cgalheaders \
		--with-helpurl="${DOCSDIR}/index.html"

ALL_TARGET=	dune

CPPFLAGS+=	-I${LOCALBASE}/ffmpeg4/include -I${LOCALBASE}/include/freetype2 -D__FREEBSD__
LDFLAGS+=	-L${LOCALBASE}/ffmpeg4/lib

CONFLICTS_INSTALL=	ocaml-dune

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dune ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/bin && ${INSTALL_SCRIPT} dune4kids illegal2vrml \
		${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/man && ${INSTALL_MAN} dune.1 illegal2vrml.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

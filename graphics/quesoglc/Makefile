# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quesoglc
PORTVERSION=	0.7.2
PORTREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free implementation of the OpenGL Character Renderer

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfribidi.so:converters/fribidi \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		gl gmake libtool localbase pathfix pkgconfig tar:bzip2 xorg
GNU_CONFIGURE=	yes
USE_GL=		gl glu
USE_XORG=	x11
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

# needs GLEW MX (multiple rendering contexts), so system glew won't go
CONFIGURE_ARGS=	--without-glew --with-fribidi

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS TEST

TEST_CONFIGURE_ENABLE=	executables
# these libs are only required for building tests, which are not
# installed, so no LIB_DEPENDS; tests also require X11 display
# and are interactive
TEST_BUILD_DEPENDS=	${LOCALBASE}/lib/libglut.so:graphics/freeglut \
			${LOCALBASE}/lib/libSM.so:x11/libSM \
			${LOCALBASE}/lib/libICE.so:x11/libICE \
			${LOCALBASE}/lib/libXi.so:x11/libXi \
			${LOCALBASE}/lib/libXmu.so:x11-toolkits/libXmu
TEST_TEST_TARGET=	check

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

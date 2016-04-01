# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quesoglc
PORTVERSION=	0.7.2
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free implementation of the OpenGL Character Renderer

LIB_DEPENDS=	libfribidi.so:converters/fribidi \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		tar:bzip2 pathfix gmake libtool
GNU_CONFIGURE=	yes
USE_GL=		gl glu glut
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
# needs GLEW MX (multiple rendering contexts), so system glew won't go
CONFIGURE_ARGS=	--without-glew --with-fribidi

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

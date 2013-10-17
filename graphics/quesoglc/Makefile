# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quesoglc
PORTVERSION=	0.7.2
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/QuesoGLC/${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free implementation of the OpenGL Character Renderer

LIB_DEPENDS=	libfribidi.so:${PORTSDIR}/converters/fribidi \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		pathfix gmake
USE_GL=		gl glu glut
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
# needs GLEW MX (multiple rendering contexts), so system glew won't go
CONFIGURE_ARGS=	--without-glew --with-fribidi

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

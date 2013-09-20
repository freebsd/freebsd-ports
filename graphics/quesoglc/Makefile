# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quesoglc
PORTVERSION=	0.7.2
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/QuesoGLC/${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free implementation of the OpenGL Character Renderer

LIB_DEPENDS=	fribidi:${PORTSDIR}/converters/fribidi \
		freetype:${PORTSDIR}/print/freetype2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USES=		pathfix
USE_GL=		gl glu glut
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
# needs GLEW MX (multiple rendering contexts), so system glew won't go
CONFIGURE_ARGS=	--without-glew --with-fribidi

PORTDOCS=	README

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	quesoglc
# Date created:		04 Jun 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	quesoglc
PORTVERSION=	0.7.2
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free implementation of the OpenGL Character Renderer

LIB_DEPENDS=	fribidi.0:${PORTSDIR}/converters/fribidi \
		freetype.9:${PORTSDIR}/print/freetype2 \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack
USE_GL=		gl glu glut
USE_LDCONFIG=	yes

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" CPPFLAGS="-I${LOCALBASE}/include"
# needs GLEW MX (multiple rendering contexts), so system glew won't go
CONFIGURE_ARGS=	--without-glew --with-fribidi

PORTDOCS=	README

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	pyro
# Date created:				07 Sep 2005
# Whom:					Igor Pokrovsky <ip@doom.homeunix.org>
#
# $FreeBSD$
#

PORTNAME=	pyro
PORTVERSION=	1.5
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://nostatic.org/pyro/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple OpenGL-based firework simulator

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg

USE_GL=		gl glut
USE_XORG=	xi xmu xext

EXAMPLES=	pyro.dsp water.jpg
PLIST_FILES=	bin/pyro ${EXAMPLES:S|^|%%EXAMPLESDIR%%/|}
PLIST_DIRS=	%%EXAMPLESDIR%%
PORTDOCS=	README

post-patch:
	@${REINPLACE_CMD} -e 's|malloc\.h|stdlib.h|g' ${WRKSRC}/*.c

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/*.c -o ${WRKSRC}/${PORTNAME} \
		-DAUXDIR=\"${EXAMPLESDIR}\" -I${WRKSRC} -I${LOCALBASE}/include \
		-L${LOCALBASE}/lib -ljpeg -lm -lXmu -lXi -lXext -lGL -lGLU -lglut

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLES:S|^|${WRKSRC}/|} ${EXAMPLESDIR}

.ifndef (NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>

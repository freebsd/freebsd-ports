# Created by: Igor Pokrovsky <ip@doom.homeunix.org>
# $FreeBSD$

PORTNAME=	pyro
PORTVERSION=	1.5
PORTREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	http://nostatic.org/pyro/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple OpenGL-based firework simulator

BROKEN=		No public distfiles
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26

USES=		jpeg
USE_GL=		gl glut
USE_XORG=	xi xmu xext

EXAMPLES=	pyro.dsp water.jpg
PLIST_FILES=	bin/pyro ${EXAMPLES:S|^|%%EXAMPLESDIR%%/|}
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|malloc\.h|stdlib.h|g' ${WRKSRC}/*.c

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/*.c -o ${WRKSRC}/${PORTNAME} \
		-DAUXDIR=\"${EXAMPLESDIR}\" -I${WRKSRC} -I${LOCALBASE}/include \
		-L${LOCALBASE}/lib -ljpeg -lm -lXmu -lXi -lXext -lGL -lGLU -lglut

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLES:S|^|${WRKSRC}/|} ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

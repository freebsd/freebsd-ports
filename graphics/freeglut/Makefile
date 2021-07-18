# Created by: thierry@pompo.net

PORTNAME=	freeglut
PORTVERSION=	3.2.1
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Open source implementation of GLUT library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:insource gl localbase:ldflags pathfix xorg
USE_LDCONFIG=	yes
USE_XORG=	ice x11 xi xrandr xxf86vm
USE_GL=		gl glu
LDFLAGS+=	-lusbhid -lm

DOCS=	download.html freeglut.html freeglut_logo.png		\
	freeglut_user_interface.html index.html ogl_sm.png	\
	progress.html structure.html
BINS=	CallbackMaker Fractals Fractals_random Lorenz One Resizer \
	multi-touch shapes smooth_opengl3 spaceball subwin timer

OPTIONS_DEFINE=	DOCS EXAMPLES

pre-configure:
.for fract in Fractals/fractals.c Fractals_random/fractals_random.c
	@${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|g"		\
		${WRKSRC}/progs/demos/${fract}
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/progs/demos/Fractals/fractals.dat ${STAGEDIR}${EXAMPLESDIR}
.for prog in ${BINS}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${prog} ${STAGEDIR}${EXAMPLESDIR}
.endfor
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."

.include <bsd.port.mk>

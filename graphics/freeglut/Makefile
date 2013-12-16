# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	freeglut
PORTVERSION=	2.8.1
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	x11@FreeBSD.org
COMMENT=	An alternative to the OpenGL Utility Toolkit (GLUT) library

LICENSE=	MIT

CONFLICTS=	libglut-[0-9].*

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_XORG=	ice xi xxf86vm xrandr
USE_GL=		glu
CONFIGURE_ARGS=	--disable-warnings
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lusbhid
USE_LDCONFIG=	yes

DOCS=	download.html freeglut.html freeglut_logo.png		\
	freeglut_user_interface.html index.html ogl_sm.png	\
	progress.html structure.html
BINS=	CallbackMaker Fractals Fractals_random Lorenz One shapes

.include <bsd.port.options.mk>

pre-configure:
.for fract in Fractals/fractals.c Fractals_random/fractals_random.c
	@${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|g"		\
		${WRKSRC}/progs/demos/${fract}
.endfor

post-build:
	@${MV} ${WRKSRC}/progs/demos/CallbackMaker/.libs/CallbackMaker	\
		${WRKSRC}/progs/demos/CallbackMaker/.libs/callbackmaker

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/progs/demos/Fractals/fractals.dat ${STAGEDIR}${EXAMPLESDIR}
.for prog in ${BINS}
	@${INSTALL_PROGRAM} ${WRKSRC}/progs/demos/${prog}/.libs/${prog:L} ${STAGEDIR}${EXAMPLESDIR}
.endfor
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif

.include <bsd.port.mk>

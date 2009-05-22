# New ports collection makefile for:	freeglut
# Date created:		Wed Apr 23 2003
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=		freeglut
PORTVERSION=		2.4.0
PORTREVISION=		4
CATEGORIES=		graphics
MASTER_SITES=		SF

MAINTAINER=		ports@FreeBSD.org
COMMENT=		An alternative to the OpenGL Utility Toolkit (GLUT) library

CONFLICTS=		libglut-[0-9]*

USE_AUTOTOOLS=		libtool:15
GNU_CONFIGURE=		yes
USE_LDCONFIG=		yes
USE_XORG=		ice
USE_GL=			glu
CONFIGURE_ARGS=		--disable-warnings
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-lusbhid"

REINPLACE_ARGS=		-i ""

DOCS=	download.html freeglut.html freeglut_logo.png		\
	freeglut_user_interface.html index.html ogl_sm.png	\
	progress.html structure.html
BINS=	CallbackMaker Fractals Fractals_random Lorenz One shapes

pre-configure:
.for fract in /fractals.c _random/fractals_random.c
	@${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|g"		\
		${WRKSRC}/progs/demos/Fractals${fract}
.endfor

post-build:
	@${MV} ${WRKSRC}/progs/demos/CallbackMaker/.libs/CallbackMaker	\
		${WRKSRC}/progs/demos/CallbackMaker/.libs/callbackmaker

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/progs/demos/Fractals/fractals.dat	\
		${EXAMPLESDIR}
.for prog in ${BINS}
	@${INSTALL_PROGRAM} ${WRKSRC}/progs/demos/${prog}/.libs/${prog:L} \
		${EXAMPLESDIR}
.endfor
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800064
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>

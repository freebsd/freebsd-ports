# Created by: Torsten Teg Grust (Torsten.Grust@uni-konstanz.de)
# $FreeBSD$

PORTNAME=	hugs98
PORTVERSION=	200609
PORTREVISION=	8
CATEGORIES=	lang haskell
MASTER_SITES=	http://cvs.haskell.org/Hugs/downloads/2006-09/
DISTNAME=	${PORTNAME}-plus-${HUGS_DATE}

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Interpreter for the functional programming language Haskell 98

BUILD_DEPENDS=	bash:shells/bash

WRKSRC=		${WRKDIR}/${DISTNAME}

HUGS_DATE=	Sep2006
USES=		bison gmake openal:al,alut
USE_GCC=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-pthreads

USE_GL=		glut
USE_XORG=	sm ice xmu xi x11

BROKEN_ia64=	dumps core during build

post-patch:
	@${REINPLACE_CMD} 's/LIBS/LIBRARIES/' ${WRKSRC}/libraries/Makefile.in
	@${REINPLACE_CMD} -e '/^install		:: install_notes/d ; \
		/^install		:: install_guide/d' \
		${WRKSRC}/src/MkInstal.in
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},g' \
		${WRKSRC}/packages/OpenGL/configure \
		${WRKSRC}/packages/GLUT/configure \
		${WRKSRC}/packages/X11/configure \
		${WRKSRC}/packages/HGL/configure
	@${REINPLACE_CMD} -e 's,"gcc","${CC}",g' \
		${WRKSRC}/hsc2hs/Main.hs

do-build:
.	for dir in src libraries docs
	cd ${WRKSRC}/${dir} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}
.	endfor

do-install:
.	for dir in src libraries demos docs
	cd ${WRKSRC}/${dir} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}
.	endfor

.include <bsd.port.mk>

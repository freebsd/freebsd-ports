# New ports collection makefile for:	hugs
# Date created:		22 September 1997
# Whom:			Torsten Teg Grust (Torsten.Grust@uni-konstanz.de)
#
# $FreeBSD$
#

PORTNAME=	hugs98
PORTVERSION=	200605
CATEGORIES=	lang haskell
MASTER_SITES=	http://cvs.haskell.org/Hugs/downloads/2006-05/
DISTNAME=	${PORTNAME}-plus-${HUGS_DATE}

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	An interpreter for the functional programming language Haskell 98

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

WRKSRC=		${WRKDIR}/${DISTNAME}

#OPTIONS=	HUGS_OPENGL "OpenGL/GLUT support" off
HUGS_DATE=	May2006
USE_BISON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
#CONFIGURE_ARGS+=	--prefix=${PREFIX} --enable-ffi
#CONFIGURE_ENV+=	CC="${CC}" CFLAGS="${CFLAGS}"

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--with-pthreads

.if (${OSVERSION} < 500000)
BROKEN=		missing data type declarations
.endif

.if !defined(WITHOUT_X11)
USE_GL=	yes
LIB_DEPENDS+=	glut.4:${PORTSDIR}/graphics/libglut
PLIST_SUB+=	X11=""
.else
BROKEN=		not supported at the moment
CONFIGURE_ARGS+=	--disable-hgl --disable-opengl --disable-alut --disable-glut --disable-x11
PLIST_SUB+=	X11="@comment "
.endif

MAN1=		hugs.1

.if ${MACHINE_ARCH:L} == "amd64"
CFLAGS+=	"-fPIC"
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^install		:: install_notes/d ; \
		/^install		:: install_guide/d' \
		${WRKSRC}/src/MkInstal.in
	@${REINPLACE_CMD} -e 's|^#!/bin/sh|#!/usr/local/bin/bash|' ${WRKSRC}/libraries/tools/make_bootlib

do-build:
.	for dir in src libraries docs
	cd ${WRKSRC}/${dir} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}
.	endfor

do-install:
.	for dir in src libraries demos docs
	cd ${WRKSRC}/${dir} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}
.	endfor

.include <bsd.port.post.mk>

# New ports collection makefile for:	hugs
# Date created:		22 September 1997
# Whom:			Torsten Teg Grust (Torsten.Grust@uni-konstanz.de)
#
# $FreeBSD$
#

PORTNAME=	hugs98
PORTVERSION=	200503
PORTREVISION=	1
CATEGORIES=	lang haskell
MASTER_SITES=	http://cvs.haskell.org/Hugs/downloads/${HUGS_DATE}/
DISTNAME=	${PORTNAME}-${HUGS_DATE}-patched

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	An interpreter for the functional programming language Haskell 98

WRKSRC=		${WRKDIR}/${DISTNAME}

#OPTIONS=	HUGS_OPENGL "OpenGL/GLUT support" off
WITH_HUGS_OPENGL=	yes
HUGS_DATE=	Mar2005
USE_BISON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
#CONFIGURE_ARGS+=	--prefix=${PREFIX} --enable-ffi
#CONFIGURE_ENV+=	CC="${CC}" CFLAGS="${CFLAGS}"

.include <bsd.port.pre.mk>

.if defined(WITH_HUGS_OPENGL)
#CONFIGURE_ARGS+=	--enable-hopengl
USE_GL=	yes
PLIST_SUB+=	X11=""
.else
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

do-build:
.	for dir in src libraries docs
	cd ${WRKSRC}/${dir} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}
.	endfor

do-install:
.	for dir in src libraries demos docs
	cd ${WRKSRC}/${dir} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}
.	endfor

.include <bsd.port.post.mk>

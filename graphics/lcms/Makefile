# New ports collection makefile for:	lcms
# Date created:		October 30, 2000
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	lcms
PORTVERSION=	1.19
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.19 \
		http://www.littlecms.com/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Light Color Management System -- a color management library

USE_GNOME=	gnomehack lthack
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include
USE_LDCONFIG=	yes
WITH_FBSD10_FIX=	yes
WRKSRC=		${WRKDIR}/lcms-1.19

OPTIONS=	TIFFICC "Build color profile applier for tiff" off \
		JPEGICC "Build color profile applier for JPEG" off

.include <bsd.port.pre.mk>

.if defined(WITH_TIFFICC)
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
PLIST_SUB+=	TIFFICC=""
MAN1+=		tifficc.1
.else
CONFIGURE_ARGS=	--without-tiff
PLIST_SUB+=	TIFFICC="@comment "
.endif

.if defined(WITH_JPEGICC)
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
PLIST_SUB+=	JPEGICC=""
MAN1+=		jpegicc.1
.else
CONFIGURE_ARGS=	--without-jpeg
PLIST_SUB+=	JPEGICC="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|^SUBDIRS =.*$$|SUBDIRS = src include|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-O3||g' ${WRKSRC}/src/Makefile.in

#
# Get rid of .la and static library files
#
post-configure:
	@${REINPLACE_CMD} -E -e \
	    '/Install the pseudo-library/,/staticlibs=/s,^,#,' ${WRKSRC}/libtool

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in doc/LCMSAPI.TXT doc/TUTORIAL.TXT tifficc/tifficc.c \
	jpegicc/jpegicc.c jpegicc/iccjpeg.c samples/wtpt.c samples/icctrans.c
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.if defined(WITH_TIFFICC)
	@(cd ${WRKSRC}/tifficc && ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} Makefile all install)
.endif

.if defined(WITH_JPEGICC)
	@(cd ${WRKSRC}/jpegicc && ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} Makefile all install)
.endif

post-build test:
	cd ${WRKSRC}/testbed && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.post.mk>

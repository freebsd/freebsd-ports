# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	lcms
PORTVERSION=	1.19
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION} \
		http://www.littlecms.com/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Light Color Management System -- a color management library

LICENSE=	MIT

OPTIONS_DEFINE=	DOCS JPEGICC TIFFICC
OPTIONS_SUB=	yes
JPEGICC_DESC=	Build color profile applier for JPEG
TIFFICC_DESC=	Build color profile applier for TIFF

CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
USE_GNOME=	gnomehack lthack
USE_LDCONFIG=	yes

JPEGICC_CONFIGURE_OFF=	--without-jpeg
JPEGICC_CONFIGURE_ON=	--with-jpeg=${LOCALBASE}
JPEGICC_LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg
TIFFICC_CONFIGURE_OFF=	--without-tiff
TIFFICC_CONFIGURE_ON=	--with-tiff=${LOCALBASE}
TIFFICC_LIB_DEPENDS=	libtiff.so:${PORTSDIR}/graphics/tiff

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS = / s| python samples||' ${WRKSRC}/Makefile.in
#	@${REINPLACE_CMD} -e '/^#ifdef __sgi/d; /^#include "sgidefs.h"/d' ${WRKSRC}/include/icc34.h.in
	@${REINPLACE_CMD} -e '/^testcms_LDFLAGS = / s|$$| -static|' ${WRKSRC}/testbed/Makefile.in
.if !${PORT_OPTIONS:MJPEGICC}
	@${REINPLACE_CMD} -e '/^SUBDIRS = / s| jpegicc||' ${WRKSRC}/Makefile.in
.endif
.if !${PORT_OPTIONS:MTIFFICC}
	@${REINPLACE_CMD} -e '/^SUBDIRS = / s| tifficc||' ${WRKSRC}/Makefile.in
.endif

post-configure:
# Get rid of .la and static library files
	@${REINPLACE_CMD} -E -e '/Install the pseudo-library/,/staticlibs=/s,^,#,' ${WRKSRC}/libtool

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} doc/LCMSAPI.TXT doc/TUTORIAL.TXT tifficc/tifficc.c \
		jpegicc/jpegicc.c jpegicc/iccjpeg.c samples/wtpt.c samples/icctrans.c ${STAGEDIR}${DOCSDIR}/
.endif

regression-test test: build
	cd ${WRKSRC}/testbed/ && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.mk>

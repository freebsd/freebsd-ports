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

OPTIONS_DEFINE=	DOCS JPEGICC TIFFICC
JPEGICC_DESC=	Build color profile applier for JPEG
TIFFICC_DESC=	Build color profile applier for TIFF

CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
USE_GNOME=	gnomehack lthack
USE_LDCONFIG=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJPEGICC}
LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg
CONFIGURE_ARGS+=--with-jpeg=${LOCALBASE}
MAN1+=		jpegicc.1
PLIST_SUB+=	JPEGICC=""
.else
CONFIGURE_ARGS+=--without-jpeg
PLIST_SUB+=	JPEGICC="@comment "
.endif

.if ${PORT_OPTIONS:MTIFFICC}
LIB_DEPENDS+=	tiff:${PORTSDIR}/graphics/tiff
CONFIGURE_ARGS+=--with-tiff=${LOCALBASE}
MAN1+=		tifficc.1
PLIST_SUB+=	TIFFICC=""
.else
CONFIGURE_ARGS+=--without-tiff
PLIST_SUB+=	TIFFICC="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS = / s| python samples||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|^testcms_LDFLAGS = .*$$|& -static|' ${WRKSRC}/testbed/Makefile.in
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
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} doc/LCMSAPI.TXT doc/TUTORIAL.TXT tifficc/tifficc.c \
		jpegicc/jpegicc.c jpegicc/iccjpeg.c samples/wtpt.c samples/icctrans.c ${DOCSDIR}/
.endif

regression-test test: build
	cd ${WRKSRC}/testbed/ && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.mk>

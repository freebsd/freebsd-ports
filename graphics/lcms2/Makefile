# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lcms2
PORTVERSION=	2.5
CATEGORIES=	graphics
MASTER_SITES=	SF/lcms/lcms/${PORTVERSION} \
		http://www.littlecms.com/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Accurate, fast, and small-footprint color management engine

LICENSE=	MIT

OPTIONS_DEFINE=	DOCS JPEGICC TIFFICC
JPEGICC_DESC=	Build color profile applier for JPEG
TIFFICC_DESC=	Build color profile applier for TIFF

CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
USE_GNOME=	gnomehack lthack
USE_LDCONFIG=	yes

MAN1=		linkicc.1 psicc.1 transicc.1
PLIST_SUB=	PORTVERSION=${PORTVERSION}

UTILS=		linkicc psicc transicc

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJPEGICC}
LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg
CONFIGURE_ARGS+=--with-jpeg=${LOCALBASE}
MAN1+=		jpgicc.1
PLIST_SUB+=	JPEGICC=""
UTILS+=		jpgicc
.else
CONFIGURE_ARGS+=--without-jpeg
PLIST_SUB+=	JPEGICC="@comment "
.endif

.if ${PORT_OPTIONS:MTIFFICC}
LIB_DEPENDS+=	tiff:${PORTSDIR}/graphics/tiff
CONFIGURE_ARGS=	--with-tiff=${LOCALBASE}
MAN1+=		tificc.1
PLIST_SUB+=	TIFFICC=""
UTILS+=		tificc
.else
CONFIGURE_ARGS+=--without-tiff
PLIST_SUB+=	TIFFICC="@comment "
.endif

post-patch:
.if empty(PORT_OPTIONS:MJPEGICC)
	@${REINPLACE_CMD} -e '/^SUBDIRS = / s| utils/jpgicc||' ${WRKSRC}/Makefile.in
.endif
.if empty(PORT_OPTIONS:MTIFFICC)
	@${REINPLACE_CMD} -e '/^SUBDIRS = / s| utils/tificc||' ${WRKSRC}/Makefile.in
.endif

post-configure:
# Get rid of .la and static library files
	@${REINPLACE_CMD} -E -e '/Install the pseudo-library/,/staticlibs=/s,^,#,' ${WRKSRC}/libtool

post-install:
	cd ${WRKSRC}/utils/ && ${INSTALL_MAN} linkicc/linkicc.1 psicc/psicc.1 transicc/transicc.1 ${MANPREFIX}/man/man1/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${DOCSDIR}/
.endif

regression-test test: build
	cd ${WRKSRC}/testbed/ && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.mk>

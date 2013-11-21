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
OPTIONS_SUB=	yes
JPEGICC_DESC=	Build color profile applier for JPEG
TIFFICC_DESC=	Build color profile applier for TIFF

CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
USE_GNOME=	gnomehack lthack
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

UTILS=		linkicc psicc transicc

JPEGICC_CONFIGURE_OFF=	--without-jpeg
JPEGICC_CONFIGURE_ON=	--with-jpeg=${LOCALBASE}
JPEGICC_LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg
TIFFICC_CONFIGURE_OFF=	--without-tiff
TIFFICC_CONFIGURE_ON=	--with-tiff=${LOCALBASE}
TIFFICC_LIB_DEPENDS=	libtiff.so:${PORTSDIR}/graphics/tiff

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJPEGICC}
UTILS+=		jpgicc
.endif

.if ${PORT_OPTIONS:MTIFFICC}
UTILS+=		tificc
.endif

post-patch:
.if !${PORT_OPTIONS:MJPEGICC}
	@${REINPLACE_CMD} -e '/^SUBDIRS = / s| utils/jpgicc||' ${WRKSRC}/Makefile.in
.endif
.if !${PORT_OPTIONS:MTIFFICC}
	@${REINPLACE_CMD} -e '/^SUBDIRS = / s| utils/tificc||' ${WRKSRC}/Makefile.in
.endif

post-configure:
# Get rid of .la and static library files
	@${REINPLACE_CMD} -E -e '/Install the pseudo-library/,/staticlibs=/s,^,#,' ${WRKSRC}/libtool

post-install:
	cd ${WRKSRC}/utils/ && ${INSTALL_MAN} linkicc/linkicc.1 psicc/psicc.1 transicc/transicc.1 ${STAGEDIR}${PREFIX}/man/man1/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${STAGEDIR}${DOCSDIR}/
.endif

regression-test test: build
	cd ${WRKSRC}/testbed/ && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.mk>

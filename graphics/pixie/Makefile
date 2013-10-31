# Created by: Igor Pokrovsky <tiamat@comset.net>
# $FreeBSD$

PORTNAME=	pixie
PORTVERSION=	2.2.6
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Pixie%20${PORTVERSION}
DISTNAME=	Pixie-src-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Photorealistic renderer with Pixar's RenderMan-like interface

LICENSE=	LGPL21 # (or later)

LIB_DEPENDS=	IlmImf:${PORTSDIR}/graphics/OpenEXR \
		tiff:${PORTSDIR}/graphics/tiff \
		fltk_gl:${PORTSDIR}/x11-toolkits/fltk

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/Pixie

USE_GL=		glu
USES=		bison pathfix
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/pixie \
		--libdir=${PREFIX}/lib/pixie \
		--with-docdir=${DOCSDIR} \
		--with-shaderdir=${DATADIR}/shaders \
		--with-ribdir=${DATADIR}/ribs \
		--with-texturedir=${DATADIR}/textures \
		--with-displaysdir=${PREFIX}/lib/pixie/displays \
		--with-modulesdir=${PREFIX}/lib/pixie/modules \
		--with-openexr-prefix=${LOCALBASE} \
		--enable-openexr-threads
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}

MAN1=		rndr.1 sdrc.1 sdrinfo.1 texmake.1
PORTDOCS=	*

CFLAGS+=	-fPIC
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.if ${OSVERSION} < 1000033
BUILD_DEPENDS+=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex
CONFIGURE_ENV+=	ac_cv_path_FLEX="${LOCALBASE}/bin/flex"
.endif

post-patch:
	@${REINPLACE_CMD} -e '/test/s|==|=|g ; \
		 s|-lpthread|-pthread|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|doc||g ; \
		 /^install-data-am:/s|install-nobase_docDATA||g' ${WRKSRC}/Makefile.in
.for file in src/ri/Makefile.in src/sdr/Makefile.in
	@${REINPLACE_CMD} -e '/^includedir/s|=.*$$|= @includedir@|g' ${WRKSRC}/${file}
.endfor

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog DEVNOTES NEWS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	@(cd ${WRKSRC}/doc && ${FIND} . ! -name "*Makefile*" | \
		${CPIO} -dump -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR})
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	pixie
# Date created:		29 Jan 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	pixie
PORTVERSION=	2.2.6
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Pixie%20${PORTVERSION}
DISTNAME=	Pixie-src-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A photorealistic renderer with Pixar's RenderMan-like interface

BUILD_DEPENDS=	flex:${PORTSDIR}/textproc/flex
LIB_DEPENDS=	IlmImf.6:${PORTSDIR}/graphics/OpenEXR \
		tiff.4:${PORTSDIR}/graphics/tiff \
		fltk_gl.1:${PORTSDIR}/x11-toolkits/fltk

NOT_FOR_ARCHS=	amd64

WRKSRC=		${WRKDIR}/Pixie

USE_GNOME=	gnomehack
USE_GL=		glu
USE_BISON=	build
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
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
CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e '/test/s|==|=|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|doc||g ; \
		 /^install-data-am:/s|install-nobase_docDATA||g' ${WRKSRC}/Makefile.in
.for file in src/ri/Makefile.in src/sdr/Makefile.in
	@${REINPLACE_CMD} -e '/^includedir/s|=.*$$|= @includedir@|g' ${WRKSRC}/${file}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog DEVNOTES LICENSE NEWS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	@(cd ${WRKSRC}/doc && ${FIND} . ! -name "*Makefile*" | \
		${CPIO} -dump -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR})
.endif

.include <bsd.port.post.mk>

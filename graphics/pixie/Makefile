# Created by: Igor Pokrovsky <tiamat@comset.net>
# $FreeBSD$

PORTNAME=	pixie
PORTVERSION=	2.2.6
PORTREVISION=	21
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Pixie%20${PORTVERSION}
DISTNAME=	Pixie-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Photorealistic renderer with Pixar's RenderMan-like interface

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libIlmImf.so:graphics/openexr \
		libtiff.so:graphics/tiff \
		libfltk_gl.so:x11-toolkits/fltk

BROKEN_aarch64=		fails to compile: use of undeclared identifier CRenderer
BROKEN_armv6=		fails to compile: use of undeclared identifier CRenderer
BROKEN_armv7=		fails to compile: use of undeclared identifier CRenderer
BROKEN_sparc64=		fails to compile

USES=		bison compiler:c++0x gl libtool pathfix tar:tgz
USE_GL=		glu
GNU_CONFIGURE=	yes
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
WRKSRC=		${WRKDIR}/Pixie
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}

PORTDOCS=	*

CFLAGS+=	-fPIC
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/test/s|==|=|g ; \
		 s|-lpthread|-pthread|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|doc||g ; \
		 /^install-data-am:/s|install-nobase_docDATA||g' \
		 ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^includedir/s|=.*$$|= @includedir@|g' \
		${WRKSRC}/src/ri/Makefile.in \
		${WRKSRC}/src/sdr/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS ChangeLog DEVNOTES NEWS \
		README ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
		'! -name "*Makefile*"')

.include <bsd.port.mk>

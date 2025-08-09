PORTNAME=	pixie
PORTVERSION=	2.2.6
PORTREVISION=	43
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Pixie%20${PORTVERSION}
DISTNAME=	Pixie-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Photorealistic renderer with Pixar's RenderMan-like interface
WWW=		https://sourceforge.net/projects/pixie/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=		fails to compile: ri/atomic.h:149:9: use of undeclared identifier CRenderer
BROKEN_armv6=		fails to compile: ri/atomic.h:149:9: use of undeclared identifier CRenderer
BROKEN_armv7=		fails to compile: ri/atomic.h:149:9: use of undeclared identifier CRenderer
BROKEN_riscv64=		fails to compile: ri/atomic.h:149:9: use of undeclared identifier CRenderer

LIB_DEPENDS=	libOpenEXR.so:graphics/openexr \
		libImath.so:math/Imath \
		libtiff.so:graphics/tiff \
		libfltk_gl.so:x11-toolkits/fltk

USES=		autoreconf bison compiler:c++0x gl libtool pathfix tar:tgz
USE_CXXSTD=	c++14
USE_GL=		glu
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
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
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/Imath
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/test/s|==|=|g ; \
		 s|-lpthread|-pthread|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^includedir/s|=.*$$|= @includedir@|g' \
		${WRKSRC}/src/ri/Makefile.am \
		${WRKSRC}/src/sdr/Makefile.am

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS ChangeLog DEVNOTES NEWS \
		README ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
		'! -name "*Makefile*"')

.include <bsd.port.mk>

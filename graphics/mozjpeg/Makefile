# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	mozjpeg
PORTVERSION=	3.2
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Improved JPEG encoder by Mozilla

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libpng.so:graphics/png

BROKEN_aarch64=		does not configure: error: SIMD support cannot be enabled
BROKEN_mips64=		does not configure: error: SIMD support cannot be enabled
BROKEN_powerpc64=	does not build: undefined reference to htole32
BROKEN_sparc64=		does not configure: error: SIMD support cannot be enabled

OPTIONS_DEFINE=	DOCS EXAMPLES SIMD TURBOJPEG
OPTIONS_DEFAULT=SIMD TURBOJPEG
OPTIONS_SUB=	yes
SIMD_DESC=	Include SIMD extensions
TURBOJPEG_DESC=	Include the TurboJPEG wrapper library and associated tests

CONFIGURE_ARGS=	--docdir=${DOCSDIR} \
		--includedir=${PREFIX}/include/${PORTNAME} \
		--libdir=${PREFIX}/lib/${PORTNAME} \
		--with-jpeg8
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}
USES=		autoreconf libtool pkgconfig

PORTDOCS=	*
PORTEXAMPLES=	*

GH_ACCOUNT=	mozilla
USE_GITHUB=	yes

SIMD_BUILD_DEPENDS=	yasm:devel/yasm
SIMD_CONFIGURE_WITH=	simd
TURBOJPEG_CONFIGURE_WITH=	turbojpeg

post-patch:
	@${REINPLACE_CMD} -e '/pkgconfig/d; /^exampledir = / s| =.*| = ${EXAMPLESDIR}|' ${WRKSRC}/Makefile.am

post-install-DOCS-on:
	cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>

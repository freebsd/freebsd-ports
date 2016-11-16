# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	mozjpeg
PORTVERSION=	3.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced JPEG encoder for the Web

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_GITHUB=	yes
GH_ACCOUNT=	mozilla

USES=		autoreconf libtool pkgconfig
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir=${PREFIX}/share/doc/${PORTNAME} \
		--includedir=${PREFIX}/include/${PORTNAME} \
		--libdir=${PREFIX}/lib/${PORTNAME} \
		--with-jpeg8 \
		--disable-static
INSTALL_TARGET=	install-strip

PLIST_SUB=	PORTNAME=${PORTNAME}

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES SIMD TURBOJPEG
OPTIONS_DEFAULT=SIMD TURBOJPEG
OPTIONS_SUB=	yes

SIMD_DESC=	Include SIMD extensions
TURBOJPEG_DESC=	Include the TurboJPEG wrapper library and associated tests

SIMD_CONFIGURE_WITH=		simd
SIMD_BUILD_DEPENDS=		yasm:devel/yasm
TURBOJPEG_CONFIGURE_WITH=	turbojpeg

BROKEN_aarch64=		Does not configure: error: SIMD support cannot be enabled
BROKEN_mips64=		Does not configure: error: SIMD support cannot be enabled
BROKEN_powerpc64=	Does not build
BROKEN_sparc64=		Does not configure: error: SIMD support cannot be enabled

post-patch:
	@${REINPLACE_CMD} -e '/^docdir/s|=.*|= ${DOCSDIR}|; \
		/^exampledir/s|=.*|= ${EXAMPLESDIR}|' \
			${WRKSRC}/Makefile.am

post-install:
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

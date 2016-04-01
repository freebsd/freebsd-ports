# $FreeBSD$

PORTNAME=	hwloc
PORTVERSION=	1.11.1
CATEGORIES=	devel
MASTER_SITES=	http://www.open-mpi.org/software/hwloc/v${PORTVERSION:R}/downloads/ \
		http://icl.cs.utk.edu/open-mpi/software/hwloc/v${PORTVERSION:R}/downloads/

MAINTAINER=	phd_kimberlite@yahoo.co.jp
COMMENT=	Portable Hardware Locality software package

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpciaccess.so:devel/libpciaccess

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static \
		--disable-opencl \
		--disable-cuda \
		--disable-nvml \
		--disable-gl
INSTALL_TARGET=	install-strip
USES=		iconv libtool pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes
USE_GNOME=	libxml2

PORTDOCS=	*

ONLY_FOR_ARCHS=		i386 amd64 armv6
ONLY_FOR_ARCHS_REASON=	has not been ported to this architecture

OPTIONS_DEFINE=	CAIRO DOCS
OPTIONS_SUB=	yes

CAIRO_CONFIGURE_OFF=	--disable-cairo --without-x
CAIRO_CONFIGURE_ON=	--enable-cairo --with-x
CAIRO_LIB_DEPENDS=	libcairo.so:graphics/cairo
CAIRO_USE=		XORG=x11

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/doxygen-doc/html/* ${STAGEDIR}${DOCSDIR}/html/.

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	hwloc
PORTVERSION=	1.8
CATEGORIES=	devel
MASTER_SITES=	http://www.open-mpi.org/software/hwloc/v${PORTVERSION}/downloads/ \
		http://icl.cs.utk.edu/open-mpi/software/hwloc/v${PORTVERSION}/downloads/

MAINTAINER=	phd_kimberlite@yahoo.co.jp
COMMENT=	Portable Hardware Locality software package

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libpciaccess.so:${PORTSDIR}/devel/libpciaccess

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-static \
			--enable-libxml2 \
			--disable-gl
USES=		pkgconfig pathfix iconv
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_GNOME=	libxml2

PORTDOCS=	*

ONLY_FOR_ARCHS=		i386 amd64 armv6
ONLY_FOR_ARCHS_REASON=	has not been ported to this architecture

OPTIONS_DEFINE=	CAIRO

CAIRO_CONFIGURE_OFF=	--disable-cairo --without-x
CAIRO_CONFIGURE_ON=	--enable-cairo --with-x
CAIRO_LIB_DEPENDS=		libcairo.so:${PORTSDIR}/graphics/cairo
CAIRO_USE=	XORG=x11

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/doxygen-doc/html/* ${STAGEDIR}${DOCSDIR}/html/.

.include <bsd.port.mk>

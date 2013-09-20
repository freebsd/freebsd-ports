# $FreeBSD$

PORTNAME=	hwloc
PORTVERSION=	1.7.2
CATEGORIES=	devel
MASTER_SITES=	http://www.open-mpi.org/software/hwloc/v${PORTVERSION:R}/downloads/ \
		http://icl.cs.utk.edu/open-mpi/software/hwloc/v${PORTVERSION:R}/downloads/

MAINTAINER=	phd_kimberlite@yahoo.co.jp
COMMENT=	Portable Hardware Locality software package

LICENSE=	BSD

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

ONLY_FOR_ARCHS=		i386 amd64
ONLY_FOR_ARCHS_REASON=	has not been ported to this architecture

OPTIONS_DEFINE=	DOCS CAIRO

NO_STAGE=	yes
.include "${.CURDIR}/Makefile.man"
.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MCAIRO)
CONFIGURE_ARGS+=	--disable-cairo \
			--without-x
.else
CONFIGURE_ARGS+=	--enable-cairo \
			--with-x
LIB_DEPENDS+=		cairo:${PORTSDIR}/graphics/cairo
USE_XORG=		x11
.endif

post-patch:
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -e \
	's|^\(install-data-am:\) install-dist_pdfDATA \(install-man\)|\1 \2|g' \
	${WRKSRC}/doc/Makefile.in
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/doxygen-doc/html/* ${DOCSDIR}/html/.
.endif

.include <bsd.port.mk>

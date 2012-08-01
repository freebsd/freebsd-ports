# New ports collection makefile for:    hwloc
# Date created: 18 Dec 2011
# Whom:         Eijiro Shibusawa <ej-sib@ice.uec.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	hwloc
PORTVERSION=	1.5
CATEGORIES=	devel
MASTER_SITES=	http://www.open-mpi.org/software/hwloc/v1.5/downloads/ \
		http://icl.cs.utk.edu/open-mpi/software/hwloc/v1.5/downloads/

MAINTAINER=	phd_kimberlite@yahoo.co.jp
COMMENT=	The Portable Hardware Locality software package

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-static \
			--enable-libxml2
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_GNOME=	libxml2 pkgconfig
MAKE_JOBS_SAFE=	yes

ONLY_FOR_ARCHS=		i386 amd64
ONLY_FOR_ARCHS_REASON=	has not been ported to this architecture

OPTIONS=	CAIRO		"Enable CAIRO support"		off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_CAIRO)
CONFIGURE_ARGS+=	--disable-cairo \
			--without-x
.else
CONFIGURE_ARGS+=	--enable-cairo \
			--with-x
LIB_DEPENDS+=		cairo:${PORTSDIR}/graphics/cairo
USE_XORG=		x11
.endif

.include "${FILESDIR}/manpages"

post-patch:
	@${REINPLACE_CMD} -e \
	's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
	${WRKSRC}/Makefile.in
.ifdef NOPORTDOCS
	@${REINPLACE_CMD} -e \
	's|^\(install-data-am:\) install-dist_pdfDATA \(install-man\)|\1 \2|g' \
	${WRKSRC}/doc/Makefile.in
.endif

post-install:
	@(cd ${MAN1PREFIX}/man/man1/ ;\
		${LN} -sf lstopo.1.gz hwloc-info.1.gz ; \
		${LN} -sf lstopo.1.gz hwloc-ls.1.gz ;\
		${LN} -sf lstopo.1.gz lstopo-no-graphics.1.gz )
.ifdef !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/html
	@${INSTALL_DATA} ${WRKSRC}/doc/doxygen-doc/html/* ${DOCSDIR}/html/.
.endif

.include <bsd.port.post.mk>

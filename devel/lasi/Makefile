# New ports collection makefile for:	lasi
# Date created:		June 2006
# Whom:			giffunip
#
# $FreeBSD$
#    $MCom: ports/devel/lasi/Makefile,v 1.1 2006/10/04 20:25:40 ahze Exp $

PORTNAME=	lasi
PORTVERSION=	1.1.0
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}%20Source
DISTNAME=	libLASi-${PORTVERSION}

MAINTAINER=	lme@FreeBSD.org
COMMENT=	C++ stream output interface for creating Postscript documents

USE_GNOME=	pango pkgconfig
USE_AUTOTOOLS=	libltdl:22
PKG_CONFIG_PATH=	${PREFIX}/libdata/pkgconfig
CONFIGURE_ENV+=	PKG_CONFIG_PATH=${PKG_CONFIG_PATH}

USE_LDCONFIG=	yes

USE_CMAKE=	yes
CMAKE_ARGS+=	${WRKSRC}	\
		-DCMAKE_INSTALL_PREFIX=${PREFIX}	\
		-DCMAKE_INSTALL_DATADIR:PATH=${DATADIR}

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	${LOCALBASE}/bin/doxygen:${PORTSDIR}/devel/doxygen
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-cmake+modules+lasi.cmake
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not compile on 6.X
.endif

pre-install:
.if defined(NOPORTEXAMPLES)
	@${REINPLACE_CMD} 's/^\(add_subdirectory(examples)\)/#\1/' ${WRKSRC}/CMakeLists.txt
.endif

post-install:
	@${MV} ${PREFIX}/lib/libLASi.so.0.0.1 ${PREFIX}/lib/libLASi.so.0
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MV} ${DATADIR}/doc/* ${DOCSDIR}/
	@${RMDIR} ${DATADIR}/doc
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${MV} ${DATADIR}/examples/* ${EXAMPLESDIR}/
	@${RMDIR} ${DATADIR}/examples
.endif
.if !defined(NOPORTEXAMPLES) && !defined(NOPORTDOCS)
	@${RM} -rf ${DATADIR}/*
.endif
	@${TEST} -d ${DATADIR} && ${RMDIR} ${DATADIR} || ${TRUE}

.include <bsd.port.post.mk>

# Created by: Randall Hopper <aa8vb@nc.rr.com>
# $FreeBSD$

PORTNAME=	shapelib
PORTVERSION=	1.3.0
PORTREVISION=	9
CATEGORIES=	devel geography
MASTER_SITES=	http://download.osgeo.org/shapelib/ \
		ftp://ftp.remotesensing.org/shapelib/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C API for reading and writing ArcView Shapefiles

LICENSE=	LGPL20

OPTIONS_DEFINE=	DOCS PROJ
OPTIONS_SUB=	yes

MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes

PROJ_LIB_DEPENDS=	libproj.so:graphics/proj

.include <bsd.port.pre.mk>

# Ref: /usr/share/mk/bsd.endian.mk
.if ${ARCH} == "amd64" || ${ARCH} == "arm" || ${ARCH} == "i386" || ${ARCH} == "ia64"
ENDIAN=		-D_LITTLE_ENDIAN
.else
ENDIAN=		-D_BIG_ENDIAN	# mips*eb, powerpc, powerpc64 and sparc
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%ENDIAN%%|${ENDIAN}|g' ${WRKSRC}/contrib/Makefile

post-patch-PROJ-off:
	@${REINPLACE_CMD} -e 's|%%PROJ%%|-DNO_PROJ4|g' ${WRKSRC}/Makefile ${WRKSRC}/contrib/Makefile

post-patch-PROJ-on:
	@${REINPLACE_CMD} -e 's|%%PROJ%%|-DPROJ4|g' ${WRKSRC}/Makefile ${WRKSRC}/contrib/Makefile

post-install:
	${LN} -s libshp.so.1 ${STAGEDIR}${PREFIX}/lib/libshp.so
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/web/*.html ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.post.mk>

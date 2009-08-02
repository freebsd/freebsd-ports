# New ports collection makefile for:	shapelib for reading ARC Shape Files
# Date created:				23 Apr 2001
# Whom:					Randall Hopper <aa8vb@nc.rr.com>
#
# $FreeBSD$
#

PORTNAME=	shapelib
PORTVERSION=	1.2.10
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://dl.maptools.org/dl/shapelib/ \
		http://sunpoet.net/distfiles/

MAINTAINER=	sunpoet@sunpoet.net
COMMENT=	C API for reading and writing ArcView Shapefiles

USE_AUTOTOOLS=	libtool:22:env
USE_LDCONFIG=	yes

OPTIONS=	PROJ4 "Cartographic Projections library" off

.include <bsd.port.pre.mk>

.if defined(WITH_PROJ4)
LIB_DEPENDS+=	proj.5:${PORTSDIR}/graphics/proj
PLIST_SUB+=	PROJ4=""
PROJ4=		-DPROJ4
.else
PLIST_SUB+=	PROJ4="@comment "
PROJ4=		-DNO_PROJ4
.endif

.if ${ARCH} == "amd64" || ${ARCH} == "i386" || ${ARCH} == "ia64"
ENDIAN=		-D_LITTLE_ENDIAN
.else		# powerpc & sparc64
ENDIAN=		-D_BIG_ENDIAN
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's#%%INSTALL%%#${INSTALL}#g' \
		-e 's#%%LIBTOOL%%#${LIBTOOL}#g' \
		-e 's#%%PREFIX%%#${PREFIX}#g' \
		-e 's#%%ENDIAN%%#${ENDIAN}#g' \
		-e 's#%%PROJ4%%#${PROJ4}#g' \
			${WRKSRC}/Makefile ${WRKSRC}/contrib/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

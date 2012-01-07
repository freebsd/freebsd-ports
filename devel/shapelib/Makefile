# New ports collection makefile for:	shapelib for reading ARC Shape Files
# Date created:				23 Apr 2001
# Whom:					Randall Hopper <aa8vb@nc.rr.com>
#
# $FreeBSD$
#

PORTNAME=	shapelib
PORTVERSION=	1.3.0
PORTREVISION=	4
CATEGORIES=	devel geography
MASTER_SITES=	http://download.osgeo.org/shapelib/ \
		ftp://ftp.remotesensing.org/shapelib/ \
		LOCAL/sunpoet
DISTNAME=	${PORTNAME}-${SHAPELIB_VER}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C API for reading and writing ArcView Shapefiles

MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${SHAPELIB_VER}

OPTIONS=	DEBUG "Debugging" off \
		PROJ "Cartographic Projections library" off

SHAPELIB_VER=	${PORTVERSION}b3

.include <bsd.port.options.mk>

.if defined(WITH_DEBUG)
DEBUG=		-DDEBUG -DDEBUG2 -g
.else
DEBUG=		# empty
.endif

.if defined(WITH_PROJ)
LIB_DEPENDS+=	proj:${PORTSDIR}/graphics/proj
PLIST_SUB+=	PROJ=""
PROJ=		-DPROJ4
.else
PLIST_SUB+=	PROJ="@comment "
PROJ=		-DNO_PROJ4
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "i386" || ${ARCH} == "ia64"
ENDIAN=		-D_LITTLE_ENDIAN
.else
ENDIAN=		-D_BIG_ENDIAN	# powerpc & sparc64
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's|%%DEBUG%%|${DEBUG}|g' \
		-e 's|%%LIBTOOL%%|${LIBTOOL}|g' \
		-e 's|%%ENDIAN%%|${ENDIAN}|g' \
		-e 's|%%PROJ%%|${PROJ}|g' \
			${WRKSRC}/Makefile ${WRKSRC}/contrib/Makefile
#.if defined(WITH_PROJ)
#	@${REINPLACE_CMD} -e '/^all:/ s|$$| contrib_tools|' ${WRKSRC}/Makefile
#.endif

#		-e 's#%%INSTALL%%#${INSTALL}#g' \
#		-e 's#%%INSTALL_PROGRAM%%#${INSTALL_PROGRAM}#g' \
#		-e 's#%%PREFIX%%#${PREFIX}#g' \

post-install:
	${LN} -s libshp.so.1 ${PREFIX}/lib/libshp.so
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/web/*.html ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>

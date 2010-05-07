# New ports collection makefile for:	shapelib for reading ARC Shape Files
# Date created:				23 Apr 2001
# Whom:					Randall Hopper <aa8vb@nc.rr.com>
#
# $FreeBSD$
#

PORTNAME=	shapelib
PORTVERSION=	1.3.0
PORTREVISION=	3
CATEGORIES=	devel geography
MASTER_SITES=	http://download.osgeo.org/shapelib/ \
		ftp://ftp.remotesensing.org/shapelib/ \
		http://sunpoet.net/distfiles/
DISTNAME=	${PORTNAME}-${SHAPELIB_VER}

MAINTAINER=	sunpoet@sunpoet.net
COMMENT=	C API for reading and writing ArcView Shapefiles

MAKE_JOBS_UNSAFE=	yes
USE_AUTOTOOLS=	libtool:22:env
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${SHAPELIB_VER}

OPTIONS=	DEBUG "Debugging" off \
		PROJ4 "Cartographic Projections library" off

SHAPELIB_VER=	${PORTVERSION}b2

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
DEBUG=		-DDEBUG -DDEBUG2 -g
.else
DEBUG=
.endif

.if ${ARCH} == "amd64" || ${ARCH} == "i386" || ${ARCH} == "ia64"
ENDIAN=		-D_LITTLE_ENDIAN
.else		# powerpc & sparc64
ENDIAN=		-D_BIG_ENDIAN
.endif

.if defined(WITH_PROJ4)
LIB_DEPENDS+=	proj:${PORTSDIR}/graphics/proj
PLIST_SUB+=	PROJ4=""
PROJ4=		-DPROJ4
.else
PLIST_SUB+=	PROJ4="@comment "
PROJ4=		-DNO_PROJ4
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's#%%DEBUG%%#${DEBUG}#g' \
		-e 's#%%INSTALL%%#${INSTALL}#g' \
		-e 's#%%INSTALL_PROGRAM%%#${INSTALL_PROGRAM}#g' \
		-e 's#%%LIBTOOL%%#${LIBTOOL}#g' \
		-e 's#%%PREFIX%%#${PREFIX}#g' \
		-e 's#%%ENDIAN%%#${ENDIAN}#g' \
		-e 's#%%PROJ4%%#${PROJ4}#g' \
			${WRKSRC}/Makefile ${WRKSRC}/contrib/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/web/*.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

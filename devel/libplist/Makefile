# $FreeBSD$

PORTNAME=	libplist
PORTVERSION=	1.10
PORTREVISION?=	0
CATEGORIES?=	devel
MASTER_SITES=	http://www.libimobiledevice.org/downloads/

MAINTAINER?=	avilla@FreeBSD.org
COMMENT?=	Library to handle Apple Property List format

LICENSE?=	LGPL21

SLAVE_PORT?=	no

USE_BZIP2=	yes
USES=		cmake pkgconfig

.if ${SLAVE_PORT} == "no"

USE_GNOME=	libxml2
CMAKE_ARGS=	-DENABLE_CYTHON:BOOL=False \
		-DENABLE_SWIG:BOOL=False
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	${LOCALBASE}/lib

PORTDOCS=	AUTHORS NEWS README

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
# Required for iconv headers (included by libxml2). Do not add to
# CFLAGS as it may break updates from old versions.
	@${REINPLACE_CMD} -e 's,$${LIBXML2_INCLUDE_DIR},$${LIBXML2_INCLUDE_DIR} ${LOCALBASE}/include,' \
		${WRKSRC}/src/CMakeLists.txt
	@${REINPLACE_CMD} -e 's,$${CMAKE_INSTALL_LIBDIR}/pkgconfig,libdata/pkgconfig,' \
		${WRKSRC}/CMakeLists.txt

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.endif # ${SLAVE_PORT} == "no"

.include <bsd.port.mk>

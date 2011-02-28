# New ports collection makefile for:	libplist
# Date created:				28 May 2010
# Whom:					Alberto Villa <avilla@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libplist
PORTVERSION=	1.3
CATEGORIES=	devel
MASTER_SITES=	http://www.libimobiledevice.org/downloads/

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	A library to handle Apple Property List format

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

USE_BZIP2=	yes
USE_GNOME=	glib20 libxml2
USE_ICONV=	yes
MAKE_JOBS_SAFE=	yes
USE_CMAKE=	yes
CFLAGS+=	-I${LOCALBASE}/include
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS README

OPTIONS=	PYTHON	"Enable Python bindings (needs Swig)" off

.include <bsd.port.options.mk>

.ifdef(WITH_PYTHON)
BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13
USE_PYTHON=	yes
CMAKE_ARGS+=	-DENABLE_PYTHON:BOOL=On
PLIST_SUB+=	PYTHON=""
.else
CMAKE_ARGS+=	-DENABLE_PYTHON:BOOL=Off
PLIST_SUB+=	PYTHON="@comment "
.endif

pre-configure:
	${REINPLACE_CMD} -e 's:$${CMAKE_INSTALL_LIBDIR}/pkgconfig:libdata/pkgconfig:' \
		${WRKSRC}/CMakeLists.txt

post-install:
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

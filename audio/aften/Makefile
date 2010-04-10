# New ports collection makefile for:	aften
# Date created:		April 3, 2010
# Whom:			Gabor Zahemszky <Gabor@Zahemszky.HU>
#
# $FreeBSD$
#

PORTNAME=	aften
PORTVERSION=	0.0.8
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	Gabor@Zahemszky.HU
COMMENT=	ATSC A/52 audio encoder

USE_BZIP2=	yes

BUILDDIR=	${WRKSRC}/portbuild
BUILD_WRKSRC=	${BUILDDIR}
INSTALL_WRKSRC=	${BUILDDIR}

USE_CMAKE=	yes
CMAKE_ARGS+=	-DCMAKE_INSTALL_PREFIX:STRING="${PREFIX}"

OPTIONS=	SHARED_LIB	"Build with shared library"	off \
		CXX_BINDINGS	"Build with C++ bindings"	off \
		DOUBLE		"Use double precision"		off

.include <bsd.port.pre.mk>

.if defined(WITH_SHARED_LIB)
CMAKE_ARGS+=	-DSHARED:BOOL=ON
.endif

.if defined(WITH_CXX_BINDINGS)
CMAKE_ARGS+=	-DBINDINGS_CXX:BOOL=ON
PLIST_SUB+=	CXX=""
.else
PLIST_SUB+=	CXX="@comment "
.endif

.if defined(WITH_SHARED_LIB) || defined(WITH_CXX_BINDINGS)
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"
PLIST_SUB+=	LIBS=""
USE_LDCONFIG=	yes
.else
PLIST_SUB+=	LIBS="@comment "
.endif

.if defined(WITH_DOUBLE)
CMAKE_ARGS+=	-DDOUBLE:BOOL=ON
.endif

do-configure:
	@${MKDIR} ${BUILDDIR}
	@cd ${BUILDDIR}; ${SETENV} ${CMAKE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} ..

.include <bsd.port.post.mk>

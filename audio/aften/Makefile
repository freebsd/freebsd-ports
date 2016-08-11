# Created by: Gabor Zahemszky <Gabor@Zahemszky.HU>
# $FreeBSD$

PORTNAME=	aften
PORTVERSION=	0.0.8
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	Gabor@Zahemszky.HU
COMMENT=	ATSC A/52 audio encoder

USES=		tar:bzip2 cmake:outsource

OPTIONS_DEFINE=		SHARED_LIB CXX_BINDINGS DOUBLE
OPTIONS_DEFAULT=

SHARED_LIB_DESC=	Build with shared library
CXX_BINDINGS_DESC=	Build with C++ bindings
DOUBLE_DESC=		Use double precision

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSHARED_LIB}
CMAKE_ARGS+=	-DSHARED:BOOL=ON
.endif

.if ${PORT_OPTIONS:MCXX_BINDINGS}
CMAKE_ARGS+=	-DBINDINGS_CXX:BOOL=ON
PLIST_SUB+=	CXX=""
.else
PLIST_SUB+=	CXX="@comment "
.endif

.if ${PORT_OPTIONS:MSHARED_LIB} || ${PORT_OPTIONS:MCXX_BINDINGS}
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"
PLIST_SUB+=	LIBS=""
USE_LDCONFIG=	yes
.else
PLIST_SUB+=	LIBS="@comment "
.endif

.if ${PORT_OPTIONS:MDOUBLE}
CMAKE_ARGS+=	-DDOUBLE:BOOL=ON
.endif

.include <bsd.port.mk>

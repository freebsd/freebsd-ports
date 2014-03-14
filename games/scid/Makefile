# Created by: ijliao
# $FreeBSD$

PORTNAME=	scid
PORTVERSION=	4.4
CATEGORIES=	games databases
MASTER_SITES=	SF/${PORTNAME}/Scid/Scid%204.4/

MAINTAINER=	bsd@volki.at
COMMENT=	Free chess database application

HAS_CONFIGURE=	yes
USES=		gmake tk:84,85,86
USE_BZIP2=	yes
USE_PYTHON=	yes

TCL_LIBRARY=	-L${LOCALBASE}/lib -ltcl${TCL_SHLIB_VER}

CONFIGURE_ARGS=	\
    BINDIR="${PREFIX}/bin" \
    SHAREDIR="${PREFIX}/share/scid" \
    THREADS="-pthread" \
    TCL_VERSION="${TCL_VER}" \
    TCL_INCLUDE="-I${TCL_INCLUDEDIR} -I${TK_INCLUDEDIR} -I${LOCALBASE}/include" \
    TCL_LIBRARY="${TCL_LIBRARY}" \
    TK_LIBRARY="${TCL_LIBRARY} -ltk${TK_SHLIB_VER} -lX11" \
    OPTIMIZE="${CXXFLAGS} -fno-rtti -fno-exceptions" \
    WARNINGS=""

ALL_TARGET=	all strip

post-configure:
	@${REINPLACE_CMD} -e 's|g++|${CXX}|g; s|gcc|${CC}|g' \
		-e '/engines/ s|SHAREDIR|DESTDIR\)$$\(&|g' \
		${WRKSRC}/Makefile \
		${WRKSRC}/engines/phalanx-scid/makefile \
		${WRKSRC}/engines/togaII1.2.1a/src/Makefile

.include <bsd.port.mk>

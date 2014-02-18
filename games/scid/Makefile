# Created by: ijliao
# $FreeBSD$

PORTNAME=	scid
PORTVERSION=	4.3
CATEGORIES=	games databases
MASTER_SITES=	SF/${PORTNAME}/Scid/Scid%204.3/

MAINTAINER=	bsd@volki.at
COMMENT=	A free chess database application

HAS_CONFIGURE=	yes
USES=		gmake tk:84,85
USE_BZIP2=	yes
USE_PYTHON=	yes
USE_GMAKE=	yes

TCL_LIBRARY=	-L${LOCALBASE}/lib -ltcl${TCL_SHLIB_VER}

CONFIGURE_ARGS=	\
    BINDIR="${PREFIX}/bin" \
    SHAREDIR="${PREFIX}/share/scid" \
    TCL_VERSION="${TCL_VER}" \
    TCL_INCLUDE="-I${TCL_INCLUDEDIR} -I${TK_INCLUDEDIR} -I${LOCALBASE}/include" \
    TCL_LIBRARY="${TCL_LIBRARY}" \
    TK_LIBRARY="${TCL_LIBRARY} -ltk${TK_SHLIB_VER} -lX11" \
    OPTIMIZE="${CXXFLAGS} -fno-rtti -fno-exceptions" \
    WARNINGS=""

ALL_TARGET=	all strip

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_STAGE=	yes
.include <bsd.port.mk>

# Created by: ijliao
# $FreeBSD$

PORTNAME=	scid
PORTVERSION=	4.3
CATEGORIES=	games databases
MASTER_SITES=	SF/${PORTNAME}/Scid/Scid%204.3/

MAINTAINER=	bsd@volki.at
COMMENT=	A free chess database application

USE_TK=		84+
INVALID_TCL_VER=	86

HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_PYTHON=	yes
USE_GMAKE=	yes

TCL_LIBRARY=	-L${LOCALBASE}/lib -ltcl${USE_TCL}

CONFIGURE_ARGS=	\
    BINDIR="${PREFIX}/bin" \
    SHAREDIR="${PREFIX}/share/scid" \
    TCL_VERSION="${TCL_VER}" \
    TCL_INCLUDE="-I${TCL_INCLUDEDIR} -I${TK_INCLUDEDIR} -I${LOCALBASE}/include" \
    TCL_LIBRARY="${TCL_LIBRARY}" \
    TK_LIBRARY="${TCL_LIBRARY} -ltk${USE_TK} -lX11" \
    OPTIMIZE="${CXXFLAGS} -fno-rtti -fno-exceptions" \
    WARNINGS=""

ALL_TARGET=	all strip

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_STAGE=	yes
.include <bsd.port.mk>

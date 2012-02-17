# ex:ts=8
# Ports collection makefile for:	scid
# Date created:			Mar 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

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
MAKE_JOBS_SAFE=	yes

TCL_LIBRARY=	-L${LOCALBASE}/lib -ltcl${USE_TCL}${_TCL_THREADS_SUFFIX}

CONFIGURE_ARGS=	\
    BINDIR="${PREFIX}/bin" \
    SHAREDIR="${PREFIX}/share/scid" \
    TCL_VERSION="${TCL_VER}" \
    TCL_INCLUDE="-I${TCL_INCLUDEDIR} -I${TK_INCLUDEDIR} -I${LOCALBASE}/include" \
    TCL_LIBRARY="${TCL_LIBRARY}" \
    TK_LIBRARY="${TCL_LIBRARY} -ltk${USE_TK}${_TCL_THREADS_SUFFIX} -lX11" \
    OPTIMIZE="${CXXFLAGS} -fno-rtti -fno-exceptions" \
    WARNINGS=""

ALL_TARGET=	all strip

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

.if defined(USE_TCL_THREADS)
TCL_LIBRARY+=	${PTHREAD_LIBS}
.endif

.include <bsd.port.post.mk>

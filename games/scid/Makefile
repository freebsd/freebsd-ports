# Created by: ijliao
# $FreeBSD$

PORTNAME=	scid
PORTVERSION=	4.6.4
PORTREVISION=	1
CATEGORIES=	games databases
MASTER_SITES=	SF/${PORTNAME}/Scid/Scid%204.6/

MAINTAINER=	bsd@volki.at
COMMENT=	Free chess database application

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

HAS_CONFIGURE=	yes
USES=		gmake python shebangfix tk:85+ zip
SHEBANG_FILES=	tcl/lang/checklangs.tcl \
		tcl/lang/propagatelang.tcl \
		tcl/lang/removetoken.tcl \
		scripts/eco2pgn.py \
		scripts/pgnfix.py \
		scripts/twic2scid.py

TCL_LIBRARY=	-L${LOCALBASE}/lib -ltcl${TCL_SHLIB_VER}

CONFIGURE_CMD=	${TCLSH} ${CONFIGURE_SCRIPT}
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

post-configure:
	@${REINPLACE_CMD} -e 's|g++|${CXX}|g; s|gcc|${CC}|g' \
		${WRKSRC}/Makefile \
		${WRKSRC}/engines/phalanx-scid/makefile \
		${WRKSRC}/engines/togaII1.2.1a/src/Makefile

.include <bsd.port.mk>

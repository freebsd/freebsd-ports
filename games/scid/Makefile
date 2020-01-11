# Created by: ijliao
# $FreeBSD$

PORTNAME=	scid
PORTVERSION=	4.7.0
DISTVERSIONPREFIX=	code-
CATEGORIES=	games databases
MASTER_SITES=	SF/${PORTNAME}/Scid/Scid%204.7/

MAINTAINER=	bsd@volki.at
COMMENT=	Free chess database application

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang gmake python shebangfix tk zip
SHEBANG_FILES=	scripts/eco2pgn.py scripts/pgnfix.py scripts/twic2scid.py \
		tcl/lang/checklangs.tcl tcl/lang/propagatelang.tcl \
		tcl/lang/removetoken.tcl

TCL_LIBRARY=	-L${LOCALBASE}/lib -ltcl${TCL_SHLIB_VER}

HAS_CONFIGURE=	yes
CONFIGURE_CMD=	${TCLSH} ${CONFIGURE_SCRIPT}
CONFIGURE_ARGS=	BINDIR="${PREFIX}/bin" \
		OPTIMIZE="${CXXFLAGS} -fno-rtti -fno-exceptions" \
		SHAREDIR="${PREFIX}/share/scid" \
		TCL_INCLUDE="-I${TCL_INCLUDEDIR} -I${TK_INCLUDEDIR} -I${LOCALBASE}/include" \
		TCL_LIBRARY="${TCL_LIBRARY}" \
		TCL_VERSION="${TCL_VER}" \
		THREADS="-pthread" \
		TK_LIBRARY="${TCL_LIBRARY} -ltk${TK_SHLIB_VER} -lX11" \
		WARNINGS=""

WRKSRC=		${WRKDIR}/${PORTNAME}

post-configure:
	@${REINPLACE_CMD} -e 's|g++|${CXX}|g; s|gcc|${CC}|g' \
		${WRKSRC}/Makefile \
		${WRKSRC}/engines/phalanx-scid/makefile

.include <bsd.port.mk>

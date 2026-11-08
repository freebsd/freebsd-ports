PORTNAME=	scid
DISTVERSIONPREFIX=	v
DISTVERSION=	5.2
DISTVERSIONSUFFIX=	.202603_src
CATEGORIES=	games databases
MASTER_SITES=	SF/${PORTNAME}/Scid/Scid%205.2/

MAINTAINER=	bsd@volki.at
COMMENT=	Free chess database application
WWW=		https://scid.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang gmake python shebangfix tk zip
USE_CXXSTD=	c++20
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

WRKSRC=		${WRKDIR}/scid-code-ad78554b4678c62652a9f3632d3dc762ae167965

post-patch:
	@${REINPLACE_CMD} -i '' 's|#!/usr/bin/wish|#!${WISH}|g' \
		${WRKSRC}/scripts/filter_spellcheck_file.tcl

post-configure:
	@${REINPLACE_CMD} -e 's|g++|${CXX}|g; s|gcc|${CC}|g' \
		${WRKSRC}/Makefile \
		${WRKSRC}/engines/phalanx-scid/makefile

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/share/scid/scid ${STAGEDIR}${PREFIX}/bin/scid
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/share/scid/engines/phalanx-scid/phalanx-scid
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/share/scid/scid

.include <bsd.port.mk>

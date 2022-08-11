PORTNAME=	libretro-mame
PORTVERSION=	20220124
PORTREVISION=	1
CATEGORIES=	emulators games

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	MAME-current for libretro

LICENSE=	BSD2CLAUSE GPLv2
LICENSE_COMB=	multi

USES=	compiler:c++11-lib gl gmake pkgconfig python:3.7,build
USE_LDCONFIG=	yes

USE_GL=	gl

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	mame
GH_TAGNAME=	ec47e94

MAKEFILE=	${WRKSRC}/Makefile.libretro

MAKE_ENV=	ARCH=${ARCH} \
		CXX="${CXX}" \
		LD="${CXX}" \
		OPT_FLAGS="${CXXFLAGS}" \
		PYTHON="${PYTHON_CMD}" \
		PYTHON_EXECUTABLE="${PYTHON_CMD}"

GENIE=	${WRKSRC}/3rdparty/genie

MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	lib/libretro/mame_libretro.so

post-patch:
	@${RM} ${WRKSRC}/3rdparty/bx/include/compat/freebsd/dirent.h
	@${RM} ${WRKSRC}/3rdparty/bx/include/compat/freebsd/signal.h
	@${ECHO_CMD} ${MV} ${GENIE}/build/gmake.freebsd ${GENIE}/build/gmake.bsd
	@${REINPLACE_CMD} -e \
		's|^\(CC \)|#\1| ; \
		s|^\(CXX \)|#\1| ; \
		s|^\(CXX:\)|#\1| ; \
		s|^\(LD \)|#\1| ; \
		s|^\(PYTHON \)|#\1| ; \
		s| .(ARCH)|| ; \
		s|FreeBSD|${OPSYS}|g' \
		${WRKSRC}/makefile \
		${GENIE}/build/gmake.freebsd/genie.make
	@${REINPLACE_CMD} -e 's|gcc|${CC}|; s|g++|${CXX}|' \
		${GENIE}/src/tools/gcc.lua \
		${GENIE}/src/tools/snc.lua \
		${GENIE}/tests/test_gmake_cpp.lua
	@${REINPLACE_CMD} -e 's|= \"gcc|= \"${CC}|; s|= \"${CXX}|= \"c++|' \
		-e "s|'CXX =|'#CXX =|; s|'CC  =|'#CC  =|; s| .(ARCH)| |g" \
		${GENIE}/src/host/scripts.c
# we can't fix two types of python shebangs, so do these manually
	@${REINPLACE_CMD} -i "" -e "s|/usr/bin/env python|${PYTHON_CMD}|" \
		${WRKSRC}/scripts/build/png*.py
	@${REINPLACE_CMD} -e 's|"python"|"${PYTHON_CMD}"|' \
		${WRKSRC}/scripts/genie.lua
	@${GREP} -rl '"png.h"' ${WRKSRC}/src | ${XARGS} ${REINPLACE_CMD} \
		-e 's|"png.h"|"localpng.h"|'
	@${REINPLACE_CMD} -e 's|"util/png.h"|"util/localpng.h"|' \
		${WRKSRC}/src/frontend/mame/ui/icorender.cpp
	@${MV} ${WRKSRC}/src/lib/util/png.h ${WRKSRC}/src/lib/util/localpng.h

do-install:
	@${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/mame_libretro.so \
		${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>

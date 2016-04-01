# Created by: trevor
# $FreeBSD$

PORTNAME=	spiralloops
PORTVERSION=	2.0.0
PORTREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	http://www.pawfal.org/Software/SpiralLoops/dload/
DISTNAME=	SpiralLoops-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Loop-based sampler

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk

GNU_CONFIGURE=	yes
MAKE_ENV=	PTHREAD_LIBS="-lpthread"
WRKSRC=		${WRKDIR}/${DISTNAME}

PLIST_FILES=	bin/SpiralLoops
PORTDOCS=	CHANGES README

DESKTOP_ENTRIES="SpiralLoops" "" "" "SpiralLoops" "" false

OPTIONS_DEFINE=	DOCS

post-patch:
	${MV} ${WRKSRC}/Makefile.in ${WRKSRC}/Makefile.in.orig
	${SED} -E "s:-ldl::g; \
		s:^CFLAGS:XCFLAGS:g; \
		s:^CXXFLAGS:XCXXFLAGS:g; \
		s:-O3::g; \
		s:CFLAGS =:CFLAGS +=:g; \
		s:CXXFLAGS=:CXXFLAGS+=:g; \
		s:-lm:-lpthread -lm:g; \
		s:/usr/X11R6:${LOCALBASE}:g; \
		s:gcc:${CC}:; s:g\+\+:${CXX}:" \
		< ${WRKSRC}/Makefile.in.orig > ${WRKSRC}/Makefile.in

	@${FIND} ${WRKSRC} -type f -name "*.C" -o -name "*.cpp" -o -name "*.h" | ${XARGS} \
	   ${REINPLACE_CMD} -e '/^#include <FL/s|.h>$$|.H>|; /^#include "FL/s|.h"$$|.H"|; \
	   s|fl_file_chooser.H|Fl_File_Chooser.H|g; s|iostream.h|iostream|; s|fstream.h|fstream|'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/SpiralLoops ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

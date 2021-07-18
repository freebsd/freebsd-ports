PORTNAME=	sharpconstruct
PORTVERSION=	0.11
PORTREVISION=	17
CATEGORIES=	graphics
MASTER_SITES=	SF/sharp3d/SharpConstruct/${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	3D modeller for organic shapes

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgtkglextmm-x11-1.2.so:x11-toolkits/gtkglextmm \
		libglademm-2.4.so:devel/libglademm24

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	uses SSE instructions

USES=		compiler:c++11-lang gl tar:bzip2 gmake pkgconfig
USE_CXXSTD=	c++11
GNU_CONFIGURE=	yes
USE_GL=		gl glu

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz
PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/include/Align.hh
	@${REINPLACE_CMD} -e 's|"/sharpconstruct|"|' ${WRKSRC}/src/MainWindow.cc
	@${REINPLACE_CMD} -e 's|/usr/share/sharpconstruct|${DATADIR}|' ${WRKSRC}/src/MainWindow.cc
	@${REINPLACE_CMD} -e '/FileDialog/,/}/ d' ${WRKSRC}/src/MainWindow.cc
	@${REINPLACE_CMD} -e 's|memalign(b,c)|malloc(c)|' ${WRKSRC}/include/Align.hh
	@${FIND} ${WRKSRC} -name Makefile.in -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e '/^DEFS / s|$$| -DDATADIR=\\"${DATADIR}\\"|'

.include <bsd.port.mk>

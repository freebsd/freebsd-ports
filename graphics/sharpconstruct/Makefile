PORTNAME=	sharpconstruct
PORTVERSION=	0.11
PORTREVISION=	21
CATEGORIES=	graphics
MASTER_SITES=	SF/sharp3d/SharpConstruct/${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	3D modeller for organic shapes
WWW=		https://sourceforge.net/projects/sharp3d/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgtkglextmm-x11-1.2.so:x11-toolkits/gtkglextmm \
		libglademm-2.4.so:devel/libglademm24

ONLY_FOR_ARCHS=	amd64 i386 powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	uses SSE instructions

USES=		compiler:c++11-lang gl tar:bzip2 gmake pkgconfig
USE_CXXSTD=	c++11
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USE_GL=		gl glu

CXXFLAGS_i386=	-msse
CXXFLAGS_powerpc64le=	-DNO_WARN_X86_INTRINSICS
CXXFLAGS_powerpc64=	-DNO_WARN_X86_INTRINSICS -mvsx
PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz
PORTDATA=	*

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64 && !defined(CPUTYPE)
CXXFLAGS+=	-mcpu=power7
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/include/Align.hh
	@${REINPLACE_CMD} -e 's|"/sharpconstruct|"|' ${WRKSRC}/src/MainWindow.cc
	@${REINPLACE_CMD} -e 's|/usr/share/sharpconstruct|${DATADIR}|' ${WRKSRC}/src/MainWindow.cc
	@${REINPLACE_CMD} -e '/FileDialog/,/}/ d' ${WRKSRC}/src/MainWindow.cc
	@${REINPLACE_CMD} -e 's|memalign(b,c)|malloc(c)|' ${WRKSRC}/include/Align.hh
	@${FIND} ${WRKSRC} -name Makefile.in -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e '/^DEFS / s|$$| -DDATADIR=\\"${DATADIR}\\"|'

.include <bsd.port.mk>

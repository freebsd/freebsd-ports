PORTNAME=	gds3d
DISTVERSION=	g20220203
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Application for rendering IC (chip) layouts in 3D

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../LICENSE.txt

USES=		gl gmake localbase:ldflags xorg
USE_XORG=	x11
USE_GL=		gl

.if !exists(/usr/include/omp.h)
BROKEN=		requires OpenMP support that is missing on this architecture
.endif

USE_GITHUB=	yes
GH_ACCOUNT=	trilomix
GH_PROJECT=	${PORTNAME:tu}
GH_TAGNAME=	173da0c

WRKSRC_SUBDIR=	linux

MAKE_ARGS=	CC=${CXX}

PLIST_FILES=	bin/${PORTNAME:tu}

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_GCC=	yes
.endif

post-patch: # workaround for https://github.com/trilomix/GDS3D/issues/14
	@${REINPLACE_CMD} -e 's|Index = NULL;|Index = 0;|' ${WRKSRC}/../libgdsto3d/gdspolygon.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME:tu} ${STAGEDIR}${PREFIX}/bin

do-test:
	@cd ${WRKSRC}/.. && \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME:tu} -a assembly/as_example.assembly

.include <bsd.port.mk>

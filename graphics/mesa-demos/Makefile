# New ports collection makefile for:    mesa-demos
# Date created:         7 Nov 2003
# Whom:                 anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	demos
PORTVERSION=	7.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mesa3d/
PKGNAMEPREFIX=	mesa-
DISTFILES=	MesaDemos-${PORTVERSION}${EXTRACT_SUFX} \
		MesaLib-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	OpenGL demos distributed with Mesa

LIB_DEPENDS=	glut.4:${PORTSDIR}/graphics/libglut

USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
ALL_TARGET=
MAKE_ARGS=	SUBDIRS="progs/demos progs/xdemos"
WRKSRC=		${WRKDIR}/Mesa-${PORTVERSION}
DATADIR=	${PREFIX}/share/mesa-demos

DEMO_PROGS=	arbfplight arbfslight arbocclude bounce clearspd cubemap \
		drawpix engine fire fogcoord fplight fslight gamma gearbox \
		gears geartrain glinfo gloss glslnoise gltestperf glutfx \
		ipers isosurf lodbias morph3d multiarb paltex pointblast \
		ray readpix reflect renormal shadowtex singlebuffer spectex \
		spriteblast stex3d streaming_rect teapot terrain tessdemo \
		texcyl texdown texenv texobj trispd tunnel tunnel2 vao_demo \
		winpos

DEMO_IMAGES=	arch.rgb bw.rgb girl.rgb girl2.rgb reflect.rgb s128.rgb \
		tile.rgb tree2.rgba tree3.rgb wrs_logo.rgb
DEMO_DATA=	geartrain.dat isosurf.dat terrain.dat

XDEMO_PROGS=	glthreads glxcontexts glxdemo glxgears glxgears_fbconfig \
		glxheads glxinfo glxpbdemo glxpixmap glxswapcontrol manywin \
		offset overlay pbdemo pbinfo wincopy xfont xrotfontdemo \
		yuvrect_client

# Generate packing list
PLIST_FILES=
.for prog in ${DEMO_PROGS}
PLIST_FILES+=	bin/${prog}
.endfor
.for prog in ${XDEMO_PROGS}
PLIST_FILES+=	bin/${prog}
.endfor
.for img in ${DEMO_IMAGES}
PLIST_FILES+=	%%DATADIR%%/images/${img}
.endfor
.for dat in ${DEMO_DATA}
PLIST_FILES+=	%%DATADIR%%/data/${dat}
.endfor
PLIST_DIRS=	%%DATADIR%%/images %%DATADIR%%/data %%DATADIR%%

post-extract:
	${CP} ${FILESDIR}/config ${WRKSRC}/configs/current
	${REINPLACE_CMD} -e 's|../images/|${DATADIR}/images/|g' \
		-e 's|geartrain.dat|${DATADIR}/data/geartrain.dat|g' \
		-e 's|terrain.dat|${DATADIR}/data/terrain.dat|g' \
		-e 's|isosurf.dat|${DATADIR}/data/isosurf.dat|g' \
		${WRKSRC}/progs/demos/*.c ${WRKSRC}/progs/xdemos/*.c

do-install:
	@for prog in ${DEMO_PROGS}; do \
		${INSTALL_PROGRAM} ${WRKSRC}/progs/demos/$$prog \
			${PREFIX}/bin ; \
	done
	@for prog in ${XDEMO_PROGS}; do \
		${INSTALL_PROGRAM} ${WRKSRC}/progs/xdemos/$$prog \
			${PREFIX}/bin ; \
	done
	${MKDIR} ${DATADIR}/images ${DATADIR}/data
	@for img in ${DEMO_IMAGES}; do \
		${INSTALL_DATA} ${WRKSRC}/progs/images/$$img \
			${DATADIR}/images ; \
	done
	@for dat in ${DEMO_DATA}; do \
		${INSTALL_DATA} ${WRKSRC}/progs/demos/$$dat ${DATADIR}/data ; \
	done

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} != xorg
IGNORE=		does not build with XFree86
.endif

.if defined(WITH_NVIDIA_GL)
CFLAGS+=	-DWITH_NVIDIA_GL=1
.endif

.include <bsd.port.post.mk>

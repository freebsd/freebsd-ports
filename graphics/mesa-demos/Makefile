# New ports collection makefile for:    mesa-demos
# Date created:         7 Nov 2003
# Whom:                 anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	demos
PORTVERSION=	6.4.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mesa3d/
PKGNAMEPREFIX=	mesa-
DISTFILES=	MesaDemos-${PORTVERSION}${EXTRACT_SUFX} \
		MesaLib-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenGL demos distributed with Mesa

LIB_DEPENDS=	glut.4:${PORTSDIR}/graphics/libglut

BROKEN=		Does not compile

USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
ALL_TARGET=
MAKE_ARGS=	SUBDIRS="progs/demos progs/osdemos"
WRKSRC=		${WRKDIR}/Mesa-${PORTVERSION}
DATADIR=	${PREFIX}/share/mesa-demos

DEMO_PROGS=	bounce clearspd cubemap drawpix fire gamma gears geartrain \
		glinfo gloss gltestperf glutfx ipers isosurf lodbias morph3d \
		multiarb occlude paltex pixeltex pointblast ray \
		readpix reflect renormal shadowtex spectex stex3d teapot \
		terrain tessdemo texcyl texdown texenv texobj trispd tunnel \
		tunnel2
DEMO_IMAGES=	bw.rgb girl.rgb reflect.rgb s128.rgb tile.rgb tree2.rgba \
		tree3.rgb wrs_logo.rgb
DEMO_DATA=	geartrain.dat isosurf.dat terrain.dat

# Generate packing list
PLIST_FILES=	bin/osdemo
.for prog in ${DEMO_PROGS}
PLIST_FILES+=	bin/${prog}
.endfor
.for img in ${DEMO_IMAGES}
PLIST_FILES+=	share/mesa-demos/images/${img}
.endfor
.for dat in ${DEMO_DATA}
PLIST_FILES+=	share/mesa-demos/data/${dat}
.endfor
PLIST_DIRS=	share/mesa-demos/images share/mesa-demos/data share/mesa-demos

post-extract:
	${CP} ${FILESDIR}/config ${WRKSRC}/configs/current
	${REINPLACE_CMD} -e 's|../images/|${DATADIR}/images/|g' \
		-e 's|geartrain.dat|${DATADIR}/data/geartrain.dat|g' \
		-e 's|terrain.dat|${DATADIR}/data/terrain.dat|g' \
		-e 's|isosurf.dat|${DATADIR}/data/isosurf.dat|g' \
		${WRKSRC}/progs/demos/*.c

do-install:
	@for prog in ${DEMO_PROGS}; do \
		${INSTALL_PROGRAM} ${WRKSRC}/progs/demos/$$prog \
			${PREFIX}/bin ; \
	done
	${INSTALL_PROGRAM} ${WRKSRC}/progs/osdemos/osdemo \
		${PREFIX}/bin ; \
	${MKDIR} ${PREFIX}/share/mesa-demos/images
	${MKDIR} ${PREFIX}/share/mesa-demos/data
	@for img in ${DEMO_IMAGES}; do \
		${INSTALL_DATA} ${WRKSRC}/progs/images/$$img \
			${DATADIR}/images ; \
	done
	@for dat in ${DEMO_DATA}; do \
		${INSTALL_DATA} ${WRKSRC}/progs/demos/$$dat ${DATADIR}/data ; \
	done

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} != xorg
IGNORE=         does not build with XFree86
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	bomb
# Date created:				2000-10-23
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	bomb
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/graphics/hacks/svgalib
DISTNAME=	${PORTNAME}

MAINTAINER=	trevor@FreeBSD.org

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		vga.1:${PORTSDIR}/graphics/svgalib

NO_PACKAGE=	"parts are under GPL, parts under X license"

DATADIR=	share/${PORTNAME}/
DOCDIR=		share/doc/${PORTNAME}/
DOCS=		COPYING README bomb.lsm guile.txt manual.txt notes.txt
PLIST=		${WRKDIR}/pkg-plist
SRCS=		acidlife anneal bomb brain cmap fast fuse gif image image_rule \
			image_seq libifs match quad rd rotor rug rug_multi \
			rug_rug shade slip sound static wave zio
.for i in ${SRCS}
OBJS+=	${i}.o
.endfor
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

pre-build:
	${ECHO} "bin/bomb" > ${PLIST}
	for i in `find -s ${WRKSRC}/suck -type f`; do \
		${ECHO} ${DATADIR}suck/`${BASENAME} $${i}` >> ${PLIST}; \
	done
.for i in cmap-data flame-data seq-data title.tif
	${ECHO} ${DATADIR}/${i} >> ${PLIST}
.endfor
.if !defined(NOPORTDOCS)
.for i in ${DOCS}
	${ECHO} ${DOCDIR}${i} >> ${PLIST}
.endfor
	${ECHO} "@dirrm "${DOCDIR} >> ${PLIST}
.endif
	${ECHO} "@dirrm "${DATADIR}/suck >> ${PLIST}
	${ECHO} "@dirrm "${DATADIR} >> ${PLIST}

do-build:
.for i in ${SRCS}
	cd ${WRKSRC} && ${CC} ${CFLAGS} -DDATA_DIR=\"${PREFIX}/${DATADIR}\" \
		-L${X11BASE}/lib \
		-I${X11BASE}/include \
		-L${LOCALBASE}/lib \
		-I${LOCALBASE}/include -c ${i}.c
.endfor
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o bomb ${OBJS} -lX11 -lvga -lm -ltiff \
		-L${LOCALBASE}/lib -L${X11BASE}/lib

do-install:
	${MKDIR} ${PREFIX}/${DATADIR}
	cd ${WRKSRC} && pax -r -w *-data suck title.tif ${PREFIX}/${DATADIR}
	${INSTALL} -c -g wheel -o root -m 4755 ${WRKSRC}/bomb ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/${DOCDIR}
.endfor
.endif

.include <bsd.port.mk>

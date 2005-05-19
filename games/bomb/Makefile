# New ports collection makefile for:	bomb
# Date created:				2000-10-23
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	bomb
PORTVERSION=	1.26
CATEGORIES=	games
MASTER_SITES=	http://www.draves.org/bomb/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive display hack for SVGAlib or X

BUILD_DEPENDS=	${LOCALBASE}/lib/libquicktime.a:${PORTSDIR}/multimedia/libquicktime
LIB_DEPENDS=	esd.2:${PORTSDIR}/audio/esound	\
		tiff.4:${PORTSDIR}/graphics/tiff \
		vga.1:${PORTSDIR}/graphics/svgalib

USE_REINPLACE=	yes
MAKE_ENV=	SCM_CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS} -I${X11BASE}/include -I${LOCALBASE}/include"
ALL_TARGET=	${PORTNAME}

PORTDOCS=	README bomb.lsm guile.txt manual.txt notes.txt

pre-configure:
.for fi in Makefile bomb-${PORTVERSION}-1.spec
	${REINPLACE_CMD} -e 's|/usr/lib/bomb|${DATADIR}|;			\
	s|/home/spot/src/quicktime4linux-1.1.9/quicktime|${LOCALBASE}/lib|;	\
	s|/usr/X11R6/lib|${X11BASE}/lib -L${LOCALBASE}/lib|;			\
	s|-lpthread|${PTHREAD_LIBS}|;						\
	s|/usr/bin/bomb|${PREFIX}/bin/bomb|;					\
	s|/usr/share/control-center/.data|${DATADIR}/.data|;			\
	s|install -d $$(DATA_DIR)|install -d ${DATADIR}/.data|;			\
	s|cp -a suck|${CP} -R suck|;						\
	s|cp -a|${INSTALL_DATA}|' ${WRKSRC}/${fi}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>

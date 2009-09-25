# New ports collection makefile for:	xv
# Date created:		30 October 1994
# Whom:			smace
#
# $FreeBSD$
#

PORTNAME=	xv
PORTVERSION=	3.10a
PORTREVISION=	11
CATEGORIES+=	graphics
MASTER_SITES=	ftp://ftp.cis.upenn.edu/pub/xv/:base \
		SF/png-mng/XV%20jumbo%20patches/20070520

DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:base \
		${DISTNAME}-jumbo-patches-20070520.tar.gz
DIST_SUBDIR=	${PORTNAME}

PATCH_SITES=	http://www.gregroelofs.com/code/
PATCHFILES=	xv-3.10a-enhancements.20070520-20081216.diff

MAINTAINER?=	dinoex@FreeBSD.org
COMMENT?=	An X11 program that displays images of various formats

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		png.5:${PORTSDIR}/graphics/png \
		jasper.4:${PORTSDIR}/graphics/jasper

USE_IMAKE=	yes
USE_XORG=	xext x11 xt
.if !defined(NOMAN)
MAN1=		bggen.1 vdcomp.1 xcmap.1 xv.1 xvp2p.1
.endif

XVDIST=		${DISTDIR}/${DIST_SUBDIR}

pre-patch:
	@${PATCH} ${PATCH_ARGS} -p1 < ${WRKDIR}/xv-3.10a-jumbo-fix-enh-patch-20070520.txt

post-patch:
	@${MV} ${WRKSRC}/config.h ${WRKSRC}/config.h.in
	@${CAT} ${WRKSRC}/config.h.in | \
		${SED} -e "s@%%LOCALBASE%%@${LOCALBASE}@" > ${WRKSRC}/config.h
.for i in ${MAN1}
	@${CP} ${WRKSRC}/docs/${i:R}.man ${WRKSRC}
.endfor
.if defined(NOMAN)
	${REINPLACE_CMD} -e 's,^InstallManPage.*$$,/\* $$& \*/,' \
		${WRKSRC}/Imakefile
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.jumbo ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.pcd ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/epsf.ps ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/xpm.ps ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/xvdocs.ps ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/xvtitle.ps ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/help ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/bmp.doc ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/gif* ${DOCSDIR}
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	xv
# Date created:		30 October 1994
# Whom:			smace
#
# $FreeBSD$
#

PORTNAME=	xv
PORTVERSION=	3.10a
PORTREVISION=	5
CATEGORIES+=	graphics
MASTER_SITES=	ftp://ftp.cis.upenn.edu/pub/xv/ \
		${MASTER_SITE_LOCAL} \
		ftp://ftp.trilon.com/pub/xv/ \
		ftp://ftp.trilon.com/pub/xv/patches/ \
		ftp://ftp.airlab.cs.ritsumei.ac.jp/pub/X/xv-jp-extension/working/
MASTER_SITE_SUBDIR=	shige/xv
# Workaround: pdf.patch, mp-tiff-patch, and xv-png-1.2d.patch must be fetched
#		from MASTER_SITE_LOCAL.
#		These are modified for applying after jp-extension-patch.
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}${PORTVERSION:S/.//}-jp-extension-rev5.3.3.tar.gz \
		jp-ext-bzip2-1.1.patch longname.patch pdf.patch mp-tiff-patch \
		xv-png-1.2d.patch xvpng-1.2d-fix3.patch
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTFILES:N*patch}

PATCH_SITES=	ftp://ftp.cis.upenn.edu/pub/xv/ \
		ftp://ftp.trilon.com/pub/xv/patches/
# Note: xpm.patch appears to already be in xvdir.c
PATCHFILES=	${DISTNAME}.JPEG-patch ${DISTNAME}.TIFF-patch \
		croppad.patch grabpatch vispatch \
		deepcolor.patch gifpatch exceed_grab.patch \
		tiff1200.patch gssafer.patch

MAINTAINER?=	flynn@energyhq.es.eu.org
COMMENT?=	An X11 program that displays images of various formats

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		png.5:${PORTSDIR}/graphics/png

USE_IMAKE=	yes
USE_PERL5_BUILD=yes
.if !defined(NOMAN)
MAN1=		bggen.1 vdcomp.1 xcmap.1 xv.1 xvp2p.1
.endif

XVDIST=		${DISTDIR}/${DIST_SUBDIR}

pre-patch:
	@${PATCH} ${PATCH_ARGS} -p1 < ${WRKDIR}/xv-jp-extension/Patch.xv310a-ext-5.3.3

post-patch:
	${PATCH} ${PATCH_ARGS} -p1 < ${XVDIST}/longname.patch
	${PATCH} ${PATCH_ARGS} -p1 < ${XVDIST}/pdf.patch
	${PATCH} ${PATCH_ARGS} -p0 < ${XVDIST}/mp-tiff-patch
	${PATCH} ${PATCH_ARGS} -p1 < ${XVDIST}/xv-png-1.2d.patch
	${PATCH} ${PATCH_ARGS} -p0 < ${XVDIST}/xvpng-1.2d-fix3.patch
	${PATCH} ${PATCH_ARGS} -p1 < ${XVDIST}/jp-ext-bzip2-1.1.patch
	@${MV} ${WRKSRC}/config.h ${WRKSRC}/config.h.in
	@${CAT} ${WRKSRC}/config.h.in | \
		${SED} -e "s@%%LOCALBASE%%@${LOCALBASE}@" > ${WRKSRC}/config.h
.for i in ${MAN1}
	@${CP} ${WRKSRC}/docs/${i:R}.man ${WRKSRC}
.endfor
.if defined(NOMAN)
	${PERL} -pi.orig -e 's,^InstallManPage.*$$,/\* $$& \*/,' ${WRKSRC}/Imakefile
.endif


post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.PNG ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/epsf.ps ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/xpm.ps ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/xvdocs.ps ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/xvtitle.ps ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/help ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/bmp.doc ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/gif* ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../xv-jp-extension/CHANGELOG.* ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../xv-jp-extension/README.PhotoCD ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../xv-jp-extension/README.xv310a-ext-5.3.3 ${DOCSDIR}/README.xv310a-ext-5.3.3.ja
	@${INSTALL_DATA} ${WRKSRC}/../xv-jp-extension/magic.add ${DOCSDIR}
.endif

.include <bsd.port.mk>

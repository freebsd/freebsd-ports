# New ports collection makefile for:	xv
# Version required:	3.10a
# Date created:		30 October 1994
# Whom:			smace
#
# $Id: Makefile,v 1.31 1998/11/25 09:01:21 asami Exp $
#

DISTNAME=	xv-3.10a
CATEGORIES?=	graphics
MASTER_SITES=	ftp://ftp.cis.upenn.edu/pub/xv/ \
		ftp://ftp.airlab.cs.ritsumei.ac.jp/pub/X/xv-jp-extension/working/ \
		http://www.yuasa.kuis.kyoto-u.ac.jp/~shige/FreeBSD/ports/xv/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		xv310a-jp-extension-rev5.3.3.tar.gz \
		croppad.patch grabpatch jp-ext-bzip2.patch longname.patch \
		mp-tiff-patch pdf.patch png-1.2d-fix.patch xv-png-1.2d.patch
DIST_SUBDIR=	xv
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} \
		xv310a-jp-extension-rev5.3.3.tar.gz

PATCH_SITES=    ftp://ftp.cis.upenn.edu/pub/xv/
PATCHFILES=     xv-3.10a.JPEG-patch xv-3.10a.TIFF-patch

MAINTAINER?=	shige@kuis.kyoto-u.ac.jp

LIB_DEPENDS=    jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff34 \
		png.3:${PORTSDIR}/graphics/png

USE_IMAKE=	yes
.if !defined(NOMAN)
MAN1=		bggen.1 vdcomp.1 xcmap.1 xv.1 xvpictoppm.1
.endif

XVDIST=		${DISTDIR}/${DIST_SUBDIR}

pre-patch:
	@${PATCH} ${PATCH_ARGS} -p1 < ${WRKDIR}/xv-jp-extension/Patch.xv310a-ext-5.3.3

post-patch:
	@${PATCH} ${PATCH_ARGS} -p0 < ${XVDIST}/croppad.patch
	@${PATCH} ${PATCH_ARGS} -p0 < ${XVDIST}/grabpatch
	@${PATCH} ${PATCH_ARGS} -p1 < ${XVDIST}/longname.patch
	@${PATCH} ${PATCH_ARGS} -p0 < ${XVDIST}/mp-tiff-patch
	@${PATCH} ${PATCH_ARGS} -p1 < ${XVDIST}/pdf.patch
	@${PATCH} ${PATCH_ARGS} -p1 < ${XVDIST}/xv-png-1.2d.patch
	@${PATCH} ${PATCH_ARGS} -p1 < ${XVDIST}/png-1.2d-fix.patch
	@${PATCH} ${PATCH_ARGS} -p1 < ${XVDIST}/jp-ext-bzip2.patch

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/xv
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xv
	@${INSTALL_DATA} ${WRKSRC}/README.PNG ${PREFIX}/share/doc/xv
	@${INSTALL_DATA} ${WRKSRC}/docs/epsf.ps ${PREFIX}/share/doc/xv
	@${INSTALL_DATA} ${WRKSRC}/docs/xpm.ps ${PREFIX}/share/doc/xv
	@${INSTALL_DATA} ${WRKSRC}/docs/xvdocs.ps ${PREFIX}/share/doc/xv
	@${INSTALL_DATA} ${WRKSRC}/docs/xvtitle.ps ${PREFIX}/share/doc/xv
	@${INSTALL_DATA} ${WRKSRC}/docs/help ${PREFIX}/share/doc/xv
	@${INSTALL_DATA} ${WRKSRC}/docs/bmp.doc ${PREFIX}/share/doc/xv
	@${INSTALL_DATA} ${WRKSRC}/docs/gif* ${PREFIX}/share/doc/xv
	@${INSTALL_DATA} ${WRKSRC}/../xv-jp-extension/CHANGELOG.* ${PREFIX}/share/doc/xv
	@${INSTALL_DATA} ${WRKSRC}/../xv-jp-extension/README.PhotoCD ${PREFIX}/share/doc/xv
	@${INSTALL_DATA} ${WRKSRC}/../xv-jp-extension/README.xv310a-ext-5.3.3 ${PREFIX}/share/doc/xv/README.xv310a-ext-5.3.3.ja
	@${INSTALL_DATA} ${WRKSRC}/../xv-jp-extension/magic.add ${PREFIX}/share/doc/xv
.endif

.include <bsd.port.mk>

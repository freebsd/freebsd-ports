# New ports collection makefile for: xdvi-17miyu + patches + vector font library
# Version required:	pl17
# Date created:		8 Nov 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $Id: Makefile,v 1.15 1998/12/23 01:27:41 steve Exp $
#

DISTNAME=	xdvi-17
PKGNAME=	ja-vfxdvi${RESOLUTION}-17
CATEGORIES=	japanese print
MASTER_SITES=	http://www.jp.FreeBSD.org/~mita/LOCAL_PORTS/ \
		ftp://ftp.hipecs.hokudai.ac.jp/pub/news-archive/fj.comp.texhax/volume95/Sep/ \
		ftp://ftp.hipecs.hokudai.ac.jp/pub/news-archive/fj.comp.texhax/volume95/Oct/ \
		ftp://ftp.hipecs.hokudai.ac.jp/pub/news-archive/fj.comp.texhax/volume95/Nov/
DISTFILES=	xdvi-17.tar.gz xdvi-17miyu.patch-beta6.gz \
		xdvi18-okagawa-patch \
		950923.02.Z 951007.02.Z 951109.04.Z

MAINTAINER=	mita@jp.FreeBSD.org

LIB_DEPENDS=	VFlib2.24:${PORTSDIR}/japanese/vflib
RUN_DEPENDS=	${LOCALBASE}/lib/fonts/pk${RESOLUTION}:${PORTSDIR}/print/pkfonts${RESOLUTION}

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	xdvi
USE_IMAKE=      yes
XMKMF=          xmkmf
EXTRACT_ONLY=	xdvi-17.tar.gz

.if !defined(RESOLUTION)
RESOLUTION=     300
.else
.if ${RESOLUTION} != 118 && ${RESOLUTION} != 240 && \
	${RESOLUTION} != 300 && ${RESOLUTION} != 360 && \
	${RESOLUTION} != 400  && ${RESOLUTION} != 600
.BEGIN:
	@${ECHO} "Error: invalid value for RESOLUTION: \"${RESOLUTION}\""
	@${ECHO} "Possible values are: 118, 240, 300, 360, 400 and 600."
	@${FALSE}
.endif
.endif

pre-patch:
	@(cd ${WRKDIR} ; \
	  ${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/950923.02.Z | uudecode ; \
	  ${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/951109.04.Z | uudecode ; \
	  uudecode ${DISTDIR}/${DIST_SUBDIR}/xdvi18-okagawa-patch ; \
	  gzip -d xdvi18.vflib.patch.gz ; \
	  ${PATCH} < ${FILESDIR}/xdvi18.vflib.patch.of.patch >/dev/null 2>&1; \
	  gzip -d xdvi-17+ptex.fixed.patch.gz ; \
	  ${PATCH} < ${FILESDIR}/xdvi-17+ptex.fixed.patch.of.patch >/dev/null 2>&1; \
	  ${MKDIR} tmp; \
	  cd tmp; \
	  ${PATCH} -f < ../xdvi18.vflib.patch >/dev/null 2>&1; \
	  cd .. ; \
	  ${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/xdvi-17miyu.patch-beta6.gz | patch -d . >/dev/null 2>&1; \
	  ${GZCAT} xdvi-pl17+markpage+toc+printdvi+paper.patch.gz | patch -d . >/dev/null 2>&1 ; \
	  ${PATCH} -d . < xdvi-17+ptex.fixed.patch >/dev/null 2>&1; \
	  ${CP} tmp/dnpzeit.c tmp/zeit.c . ; \
	)

post-patch:
.if defined(BATCH)
	@(cd ${WRKDIR}; sh ${FILESDIR}/customize.sh ${RESOLUTION} BATCH)
.else
	@(cd ${WRKDIR}; sh ${FILESDIR}/customize.sh ${RESOLUTION})
.endif

.include <bsd.port.mk>

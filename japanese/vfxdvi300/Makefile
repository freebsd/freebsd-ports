# New ports collection makefile for: xdvi-17miyu + patches + vector font library
# Version required:	1.7
# Date created:		8 Nov 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $Id: Makefile,v 1.1.1.1 1996/11/09 12:59:07 asami Exp $
#

DISTNAME=	xdvi-17
PKGNAME=	jp-vfxdvi${RESOLUTION}-1.7
CATEGORIES=	japanese print
MASTER_SITES=	ftp://bacchus.in.kobe-u.ac.jp/pub/tex/dviware/xdvi17/ \
		ftp://bacchus.in.kobe-u.ac.jp/pub/tex/dviware/xdvi18/ \
		ftp://ftp.hipecs.hokudai.ac.jp/pub/news-archive/fj.comp.texhax/volume95/Sep/ \
		ftp://ftp.hipecs.hokudai.ac.jp/pub/news-archive/fj.comp.texhax/volume95/Oct/ \
		ftp://ftp.hipecs.hokudai.ac.jp/pub/news-archive/fj.comp.texhax/volume95/Nov/
DISTFILES=	xdvi-17.tar.gz xdvi-17miyu.patch-beta6.gz \
		xdvi18-okagawa-patch \
		950923.02.Z 951007.02.Z 951109.04.Z

MAINTAINER=	mita@jp.FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/VFlib.a:${PORTSDIR}/japanese/vflib
RUN_DEPENDS= 	${LOCALBASE}/lib/VFlib/vfontcap:${PORTSDIR}/japanese/vflib

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	xdvi
USE_IMAKE=      yes
XMKMF=          xmkmf
EXTRACT_ONLY=	xdvi-17.tar.gz

.if !defined(RESOLUTION)
RESOLUTION=     300
RESOLUTION_UNSPECIFIED= yes
.else
.if ${RESOLUTION} != 118 && ${RESOLUTION} != 240 && \
	${RESOLUTION} != 300 && ${RESOLUTION} != 360 && \
	${RESOLUTION} != 400  && ${RESOLUTION} != 600
RESOLUTION_INVALID=     yes
.endif
.endif

pre-fetch:
.if defined(RESOLUTION_UNSPECIFIED)
	@echo "Building xdvi with ${RESOLUTION}dpi fonts."
	@echo "Set the environment variable RESOLUTION if you want"
	@echo "it to use other resolutions."
	@echo "Possible values are: 118, 240, 300 (default), 360, 400 and 600."
.elif defined(RESOLUTION_INVALID)
	@echo "Error: invalid value for RESOLUTION: \"${RESOLUTION}\""
	@echo "Possible values are: 118, 240, 300 (default), 360, 400 and 600."
	@/usr/bin/false
.endif

pre-patch:
	@(cd ${WRKDIR} ; \
	  ${GZCAT} ${DISTDIR}/950923.02.Z | uudecode ; \
	  ${GZCAT} ${DISTDIR}/951109.04.Z | uudecode ; \
	  uudecode ${DISTDIR}/xdvi18-okagawa-patch ; \
	  gzip -d xdvi18.vflib.patch.gz ; \
	  ${PATCH} < ${FILESDIR}/xdvi18.vflib.patch.of.patch >/dev/null 2>&1; \
	  gzip -d xdvi-17+ptex.fixed.patch.gz ; \
	  ${PATCH} < ${FILESDIR}/xdvi-17+ptex.fixed.patch.of.patch >/dev/null 2>&1; \
	  mkdir tmp; \
	  cd tmp; \
	  ${PATCH} -f < ../xdvi18.vflib.patch >/dev/null 2>&1; \
	  cd .. ; \
	  ${GZCAT} ${DISTDIR}/xdvi-17miyu.patch-beta6.gz | patch -d . >/dev/null 2>&1; \
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

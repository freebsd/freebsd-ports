# New ports collection makefile for: xdvi-17miyu + patches + vector font library
# Date created:		8 Nov 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vfxdvi
PORTVERSION=	17
PORTREVISION=	1
CATEGORIES=	japanese print
MASTER_SITES=	${MASTER_SITE_PORTS_JP} \
		ftp://ftp.hipecs.hokudai.ac.jp/pub/news-archive/fj.comp.texhax/volume95/Sep/ \
		ftp://ftp.hipecs.hokudai.ac.jp/pub/news-archive/fj.comp.texhax/volume95/Oct/ \
		ftp://ftp.hipecs.hokudai.ac.jp/pub/news-archive/fj.comp.texhax/volume95/Nov/
PKGNAMESUFFIX=	${RESOLUTION}
DISTNAME=	xdvi-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		xdvi-${PORTVERSION}miyu.patch-beta6.gz \
		xdvi18-okagawa-patch \
		950923.02.Z \
		951007.02.Z \
		951109.04.Z
DIST_SUBDIR=	xdvi
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	mita@FreeBSD.org

LIB_DEPENDS=	VFlib2.24:${PORTSDIR}/japanese/vflib
RUN_DEPENDS=	${LOCALBASE}/lib/fonts/pk${RESOLUTION}:${PORTSDIR}/print/pkfonts${RESOLUTION}

NO_WRKSUBDIR=	yes
USE_IMAKE=      yes
XMKMF=	xmkmf

MAN1=		xdvi.1

.if !defined(RESOLUTION)
RESOLUTION=	300
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
	  ${GUNZIP_CMD} xdvi18.vflib.patch.gz ; \
	  ${PATCH} < ${FILESDIR}/xdvi18.vflib.patch.of.patch >/dev/null 2>&1; \
	  ${GUNZIP_CMD} xdvi-${PORTVERSION}+ptex.fixed.patch.gz ; \
	  ${PATCH} < ${FILESDIR}/xdvi-${PORTVERSION}+ptex.fixed.patch.of.patch >/dev/null 2>&1; \
	  ${MKDIR} tmp; \
	  cd tmp; \
	  ${PATCH} -f < ../xdvi18.vflib.patch >/dev/null 2>&1; \
	  cd .. ; \
	  ${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/xdvi-${PORTVERSION}miyu.patch-beta6.gz | ${PATCH} -d . >/dev/null 2>&1; \
	  ${GZCAT} xdvi-pl${PORTVERSION}+markpage+toc+printdvi+paper.patch.gz | ${PATCH} -d . >/dev/null 2>&1 ; \
	  ${PATCH} -d . < xdvi-${PORTVERSION}+ptex.fixed.patch >/dev/null 2>&1; \
	  ${CP} tmp/dnpzeit.c tmp/zeit.c . ; \
	)

post-patch:
.if defined(BATCH)
	@(cd ${WRKDIR}; ${SH} ${FILESDIR}/customize.sh ${RESOLUTION} BATCH)
.else
	@(cd ${WRKDIR}; ${SH} ${FILESDIR}/customize.sh ${RESOLUTION})
.endif

.include <bsd.port.mk>

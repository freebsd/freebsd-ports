# New ports collection makefile for: jisx0213-fonts
# Date created:		Jun 1 2001
# Whom:			Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	jisx0213-fonts
PORTVERSION=	1.03
PORTREVISION=	4
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://www.mars.sphere.ne.jp/imamura/
DISTFILES=	jiskan16-2000-1.bdf.gz jiskan16-2000-2.bdf.gz \
		K14-1.bdf.gz K14-2.bdf.gz K12-1.bdf.gz K12-2.bdf.gz

MAINTAINER=	yoichi@eken.phys.nagoya-u.ac.jp

BUILD_DEPENDS=	mkbold:${PORTSDIR}/x11-fonts/mkbold \
		mkitalic:${PORTSDIR}/x11-fonts/mkitalic

NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes
FONTSDIR=	lib/X11/fonts/local

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
BUILD_DEPENDS+=	bdftopcf:${PORTSDIR}/x11/XFree86-4-clients
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.endif

EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=	-p
EXTRACT_AFTER_ARGS=	${WRKDIR}

MAKE_ENV=	FONTSDIR=${FONTSDIR}
PLIST_SUB=	FONTSDIR=${FONTSDIR}

post-extract:
	@${CP} ${FILESDIR}/Makefile.in ${WRKDIR}/Makefile
	@(cd ${WRKDIR}; ${GUNZIP_CMD} *.gz)

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGREQ} ${PKGNAME} INSTALL

post-install:
	@(cd ${PREFIX}/${FONTSDIR}; mkfontdir)

.include <bsd.port.post.mk>

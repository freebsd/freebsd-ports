# New ports collection makefile for: jisx0213-fonts
# Date created:		Jun 1 2001
# Whom:			Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	jisx0213-fonts
PORTVERSION=	1.03
PORTREVISION=	3
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://www.mars.sphere.ne.jp/imamura/
DISTFILES=	jiskan16-2000-1.bdf.gz jiskan16-2000-2.bdf.gz \
		K14-1.bdf.gz K14-2.bdf.gz K12-1.bdf.gz K12-2.bdf.gz

MAINTAINER=	yoichi@eken.phys.nagoya-u.ac.jp

NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes
FONTSDIR=	lib/X11/fonts/local

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
BUILD_DEPENDS+=	bdftopcf:${PORTSDIR}/x11/XFree86-4-clients
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.endif

FONTNAMES=	jiskan16-2000-1 jiskan16-2000-2 \
		K14-1 K14-2 K12-1 K12-2
PLIST_SUB=	FONTSDIR=${FONTSDIR}

do-extract:
	@${MKDIR} ${WRKDIR}

do-build:
.for i in ${FONTNAMES}
	(cd ${WRKSRC} ; \
	${GZCAT} ${DISTDIR}/${i}.bdf.gz | bdftopcf -o ${i}.pcf ; \
	${GZIP_CMD} ${i}.pcf)
.endfor

do-install:
	${MKDIR} ${PREFIX}/${FONTSDIR}
.for i in ${FONTNAMES}
	(cd ${WRKSRC} ; ${INSTALL_DATA} ${i}.pcf.gz ${PREFIX}/${FONTSDIR})
.endfor
	mkfontdir ${PREFIX}/${FONTSDIR}

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGREQ} ${PKGNAME} INSTALL

.include <bsd.port.post.mk>

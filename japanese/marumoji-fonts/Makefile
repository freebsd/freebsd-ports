# New ports collection makefile for: marumoji-fonts
# Date created:		Jun 1 2001
# Whom:			Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	marumoji-fonts
PORTVERSION=	1.0
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://mlnews.com/marumoji/src/ \
		${MASTER_SITE_LOCAL} \
		ftp://ftp.lavender.org/pub/x11/fonts/
MASTER_SITE_SUBDIR=	yoichi
DISTFILES=	maru14.pcf.gz maru16.pcf.gz maru18.pcf.gz \
		7x14maru.bdf.gz 7x14rkmaru.bdf.gz \
		8x16maru.bdf.gz 8x16rkmr.bdf.gz \
		9x18maru.bdf.gz 9x18rkmr.bdf.gz

MAINTAINER=	yoichi@FreeBSD.org

NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes
FONTSDIR=	lib/X11/fonts/local

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
BUILD_DEPENDS+=	bdftopcf:${PORTSDIR}/x11/XFree86-4-clients
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.endif

BDFFONTS=	7x14maru.bdf.gz 7x14rkmaru.bdf.gz 8x16maru.bdf.gz \
		8x16rkmr.bdf.gz 9x18maru.bdf.gz 9x18rkmr.bdf.gz
FONTSIZE=	7x14 8x16 9x18
PLIST_SUB=	FONTSDIR=${FONTSDIR}

do-extract:
	@${MKDIR} ${WRKDIR}
.for i in ${BDFFONTS}
	@${CP} ${DISTDIR}/${i} ${WRKDIR}
	@${GUNZIP_CMD} ${WRKDIR}/${i}
.endfor
	@${MV} ${WRKDIR}/7x14rkmaru.bdf ${WRKDIR}/7x14rkmr.bdf

do-build:
.for i in ${FONTSIZE}
	(cd ${WRKSRC} ; \
	bdftopcf ${i}maru.bdf > ${i}maru.pcf ; ${GZIP_CMD} ${i}maru.pcf; \
	bdftopcf ${i}rkmr.bdf > ${i}rkmr.pcf ; ${GZIP_CMD} ${i}rkmr.pcf )
.endfor

do-install:
	${MKDIR} ${PREFIX}/${FONTSDIR}
	(cd ${DISTDIR} ; ${INSTALL_DATA} maru14.pcf.gz maru16.pcf.gz maru18.pcf.gz ${PREFIX}/${FONTSDIR})
.for i in ${FONTSIZE}
	(cd ${WRKSRC} ; ${INSTALL_DATA} ${i}maru.pcf.gz ${i}rkmr.pcf.gz ${PREFIX}/${FONTSDIR})
.endfor
	mkfontdir ${PREFIX}/${FONTSDIR}
	${MKDIR} ${PREFIX}/share/doc/marumoji-fonts
	${INSTALL_DATA} ${FILESDIR}/LICENSE ${PREFIX}/share/doc/marumoji-fonts

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGREQ} ${PKGNAME} INSTALL

.include <bsd.port.post.mk>

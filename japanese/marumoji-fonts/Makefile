# New ports collection makefile for: marumoji-fonts
# Date created:		Jun 1 2001
# Whom:			Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	marumoji-fonts
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://mlnews.com/marumoji/src/ \
		${MASTER_SITE_LOCAL} \
		ftp://ftp.lavender.org/pub/x11/fonts/
MASTER_SITE_SUBDIR=	yoichi
DISTFILES=	maru14.bdf.v13.gz maru18.bdf.v10.gz \
		7x14maru.bdf.gz 7x14rkmaru.bdf.gz \
		m18to16.sed \
		8x16maru.bdf.gz 8x16rkmr.bdf.gz \
		9x18maru.bdf.gz 9x18rkmr.bdf.gz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yoichi@FreeBSD.org
COMMENT=	Japanese marumoji fonts

BUILD_DEPENDS=	mkbold:${PORTSDIR}/x11-fonts/mkbold-mkitalic \
		bdftopcf:${X_CLIENTS_PORT}
RUN_DEPENDS=	mkfontdir:${X_CLIENTS_PORT}

NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes
FONTSDIR=	lib/X11/fonts/local

.include <bsd.port.pre.mk>

EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=	-p
EXTRACT_AFTER_ARGS=	${WRKDIR}

MAKE_ENV=	FONTSDIR=${FONTSDIR}
PLIST_SUB=	FONTSDIR=${FONTSDIR}

post-extract:
	@${MV} ${WRKDIR}/maru14.bdf.v13.gz ${WRKDIR}/maru14.bdf.gz
	@${MV} ${WRKDIR}/maru18.bdf.v10.gz ${WRKDIR}/maru18.bdf.gz
	@${CP} ${FILESDIR}/Makefile.in ${WRKDIR}/Makefile
	@(cd ${WRKDIR}; ${GUNZIP_CMD} *.gz)

pre-build:
	@(cd ${WRKDIR}; ${SED} -f m18to16.sed < maru18.bdf > maru16.bdf)
pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGREQ} ${PKGNAME} INSTALL

post-install:
	@(cd ${PREFIX}/${FONTSDIR}; mkfontdir)
	${MKDIR} ${PREFIX}/share/doc/marumoji-fonts
	${INSTALL_DATA} ${FILESDIR}/LICENSE ${PREFIX}/share/doc/marumoji-fonts

.include <bsd.port.post.mk>

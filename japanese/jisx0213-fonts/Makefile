# New ports collection makefile for: jisx0213-fonts
# Date created:		Jun 1 2001
# Whom:			Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	jisx0213-fonts
PORTVERSION=	1.06
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://www12.ocn.ne.jp/~imamura/ \
		http://gitatsu.hp.infoseek.co.jp/bdf/:yagi
DISTFILES=	jiskan16-2000-1.bdf.gz jiskan16-2000-2.bdf.gz \
		K14-1.bdf.gz K14-2.bdf.gz K12-1.bdf.gz K12-2.bdf.gz \
		jiskan24-2000-1.bdf.gz:yagi jiskan24-2000-2.bdf.gz:yagi

MAINTAINER=	yoichi@FreeBSD.org
COMMENT=	Japanese jisx0213 fonts

BUILD_DEPENDS=	mkbold:${PORTSDIR}/x11-fonts/mkbold-mkitalic \
		bdftopcf:${X_CLIENTS_PORT}
RUN_DEPENDS=	mkfontdir:${X_CLIENTS_PORT}

NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes
FONTSDIR=	lib/X11/fonts/local

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

.include <bsd.port.mk>

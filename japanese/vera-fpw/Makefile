# New ports collection makefile for:	V.E.R.A - JIS X 4081 format version
# Date created:        	00/06/19
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vera-fpw
PORTVERSION=	${VERA_VER}.${VERAFPW_VER}
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/vera/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	vera
DISTNAME=	vera-${VERA_VER}-fpw${VERAFPW_VER}-src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		vera-${VERA_VER}.tar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	taoka@FreeBSD.org

BUILD_DEPENDS=	fpwmake:${PORTSDIR}/japanese/freepwing \
		catdump:${PORTSDIR}/japanese/epwutil

WRKSRC=		${WRKDIR}/vera-${VERA_VER}-fpw${VERAFPW_VER}
VERAFPW_VER=	1.0
VERA_VER=	1.6

post-extract:
	cd ${WRKSRC}; \
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${_DISTDIR}/vera-${VERA_VER}.tar.gz \
		${EXTRACT_AFTER_ARGS}

pre-build:
	cd ${WRKSRC}/vera-${VERA_VER}; \
	makeinfo --no-split vera.texi

do-build:
	cd ${WRKSRC}; \
	fpwmake > /dev/null; \
	fpwmake catalogs

do-install:
	${MKDIR} ${PREFIX}/share/dict/vera-fpw/vera/data
	${INSTALL_DATA} ${WRKSRC}/honmon ${PREFIX}/share/dict/vera-fpw/vera/data
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/vera-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/vera-fpw
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/vera-fpw
	${INSTALL_DATA} ${WRKSRC}/vera-${VERA_VER}/vera.texi \
		${PREFIX}/share/doc/vera-fpw
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	xv-m17n
# Version required:	3.10a
# Date created:		07 Oct 1998
# Whom:			Shigeyuki FUKUSHIMA (shige@kuis.kyoto-u.ac.jp)
#
# $FreeBSD$
#

PKGNAME=	xv-m17n-3.10a
CATEGORIES=	graphics

MAINTAINER=	shige@FreeBSD.org

MASTERDIR=	${.CURDIR}/../../graphics/xv
PKGDIR=		${.CURDIR}/pkg

MAKE_ENV=	LOCALE_EXTENSION=-DTV_MULTILINGUAL

RUN_DEPENDS=	xv:${.CURDIR}/../../graphics/xv

NOMAN=		yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/xv ${PREFIX}/bin/xv-m17n
	@if [ ! -f ${PREFIX}/bin/xv.orig ]; then \
	    ${MV} ${PREFIX}/bin/xv ${PREFIX}/bin/xv.orig ;\
	else \
	    ${RM} ${PREFIX}/bin/xv ;\
	fi
	@${LN} -sf ${PREFIX}/bin/xv-m17n ${PREFIX}/bin/xv

.include "${MASTERDIR}/Makefile"

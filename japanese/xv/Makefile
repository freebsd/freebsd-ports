# New ports collection makefile for:	ja-xv
# Date created:		07 Oct 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

CATEGORIES=	japanese

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An X11 program that displays images of various formats with japanization

MASTERDIR=	${.CURDIR}/../../graphics/xv
PKGDIR=		${.CURDIR}

MAKE_ENV=	LOCALE_EXTENSION=-DTV_L10N

RUN_DEPENDS=	xv:${.CURDIR}/../../graphics/xv

NOMAN=		yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/xv ${PREFIX}/bin/ja-xv
	@if [ ! -f ${PREFIX}/bin/xv.orig ]; then \
	    ${MV} ${PREFIX}/bin/xv ${PREFIX}/bin/xv.orig ;\
	else \
	    ${RM} ${PREFIX}/bin/xv ;\
	fi
	@${LN} -sf ${PREFIX}/bin/ja-xv ${PREFIX}/bin/xv

.include "${MASTERDIR}/Makefile"

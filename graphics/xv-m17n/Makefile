# New ports collection makefile for:	xv-m17n
# Date created:		07 Oct 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-m17n

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An X11 program that displays images of various formats with multilingualization

MASTERDIR=	${.CURDIR}/../../graphics/xv
PKGDIR=		${.CURDIR}

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

# New ports collection makefile for:	ja-xv
# Version required:	3.10a
# Date created:		07 Oct 1998
# Whom:			Shigeyuki FUKUSHIMA (shige@kuis.kyoto-u.ac.jp)
#
# $Id$
#

PKGNAME=	ja-xv-3.10a
CATEGORIES=	japanese graphics

MAINTAINER=	shige@kuis.kyoto-u.ac.jp

# can't use PORTSDIR here, since we haven't included bsd.port.mk
FILESDIR=	${.CURDIR}/../../graphics/xv/files
PATCHDIR=	${.CURDIR}/../../graphics/xv/patches

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

.include <${.CURDIR}/../../graphics/xv/Makefile>

# New ports collection makefile for:	e2ps
# Version required:	4.0
# Date created:		27 Nov 1998
# Whom:			Daisuke Kawahara <kawahara@pine.kuee.kyoto-u.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	e2ps-4.0
PKGNAME=	ja-e2ps-4.0
CATEGORIES=	japanese print
MASTER_SITES=	ftp://pine.kuee.kyoto-u.ac.jp/pub/e2ps/

MAINTAINER=	kawahara@pine.kuee.kyoto-u.ac.jp

WRKSRC=		${WRKDIR}/e2ps

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/e2ps ${PREFIX}/bin
	${LN} -sf ${PREFIX}/bin/e2ps ${PREFIX}/bin/e2lpr

.include <bsd.port.mk>

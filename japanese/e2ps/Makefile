# New ports collection makefile for:	e2ps
# Date created:		27 Nov 1998
# Whom:			Daisuke Kawahara <kawahara@pine.kuee.kyoto-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	e2ps
PORTVERSION=	4.0
CATEGORIES=	japanese print
MASTER_SITES=	ftp://pine.kuee.kyoto-u.ac.jp/pub/e2ps/

MAINTAINER=	kawahara@pine.kuee.kyoto-u.ac.jp
COMMENT=	Text file to postscript converter (with Japanese support)

WRKSRC=		${WRKDIR}/e2ps

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501000
BROKEN=		"Does not compile"
.endif


do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/e2ps ${PREFIX}/bin
	${LN} -sf ${PREFIX}/bin/e2ps ${PREFIX}/bin/e2lpr

.include <bsd.port.post.mk>

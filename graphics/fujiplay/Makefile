# New ports collection makefile for:	fujiplay
# Date created:		20 Sep 1999
# Whom:			KIRIYAMA Kazuhiko<kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	fujiplay
PORTVERSION=	1.33
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://topo.math.u-psud.fr/~bousch/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Digital camera downloading tool for Fujifilm digital cameras

NO_WRKSUBDIR=	yes

PORTSDOC=	README fujiplay.lsm mx700-commands.html

do-install:
	(cd ${WRKDIR}; ${INSTALL_PROGRAM} fujiplay yycc2ppm ${PREFIX}/bin)
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/fujiplay
.for f in ${PORTSDOC}
	${INSTALL_DATA} ${WRKDIR}/${f} ${PREFIX}/share/doc/fujiplay
.endfor
.endif

.include <bsd.port.mk>

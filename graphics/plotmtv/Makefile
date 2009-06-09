# New ports collection makefile for:	Plotmtv
# Date created:		19 October 1996
# Whom:			pgs
#
# $FreeBSD$
#

PORTNAME=	plotmtv
PORTVERSION=	1.4.1
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
DISTNAME=	Plotmtv${PORTVERSION}

MASTER_SITE_SUBDIR=	applications
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A multipurpose X11 plotting program

USE_IMAKE=	yes
USE_XORG=	x11 xext xt
ALL_TARGET=	World
MAN1=		plotmtv.1

post-patch:
	@${FIND} ${WRKSRC} -name \*.c | ${XARGS} ${REINPLACE_CMD} -e 's/<malloc.h>/<stdlib.h>/'

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR}  ${PREFIX}/share/doc/plotmtv/Tests
	@${INSTALL_DATA} ${WRKSRC}/Docs/DataFormat.ps.Z \
		${PREFIX}/share/doc/plotmtv
	@${INSTALL_SCRIPT} ${WRKSRC}/Tests/run.csh ${WRKSRC}/Tests/run.sh \
		${PREFIX}/share/doc/plotmtv/Tests
.for f in README test_abs.mtv test_abs2.mtv test_annot.mtv \
	test_annot2.mtv test_axisflip.mtv test_axislabel.mtv \
	test_bar.mtv test_column.mtv test_column2.mtv \
	test_ctrcolors.mtv test_ctrelb.mtv test_ctrelb2.mtv \
	test_ctrelb3.mtv test_ctrs.mtv test_curve2D.mtv \
	test_curve3D.mtv test_curve3D2.mtv test_exp.mtv \
	test_fillclrs.mtv test_fillclrs2.mtv test_grid4D.mtv \
	test_histogram.mtv test_lines.mtv test_log.mtv \
	test_markers.mtv test_prob.mtv test_pyramid.mtv \
	test_smallnum.mtv test_spln.mtv test_trictr.mtv \
	test_vector.mtv test_vector2.mtv
	@${INSTALL_DATA} ${WRKSRC}/Tests/${f} ${PREFIX}/share/doc/plotmtv/Tests
.endfor
.endif

.include	<bsd.port.mk>

# New ports collection makefile for:   txtmerge
# Version required:     1.01
# Date created:         20 Oct 1996
# Whom:                 Yukihiro Nakai <nakai@mlab.t.u-tokyo.ac.jp>
#
# $Id$
#

DISTNAME=	txtmerge-1.01
CATEGORIES=     graphics
MASTER_SITES=   ftp://ftp.portal.com/pub/podlipec/ \
		ftp://rzbsdi01.uni-trier.de//pub/unix/X11/application/xanim/
DISTFILES=	txtmerge101.tar.Z

MAINTAINER=     nakai@mlab.t.u-tokyo.ac.jp

WRKSRC=		${WRKDIR}/txtmerge
ALL_TARGET=	txtmerge

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/txtmerge ${PREFIX}/bin
	@mkdir -p ${PREFIX}/share/doc/txtmerge
	${INSTALL_DATA} ${WRKSRC}/txtmerge.doc ${PREFIX}/share/doc/txtmerge


.include <bsd.port.mk>

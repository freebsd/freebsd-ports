# New ports collection makefile for:	txtmerge
# Version required:	1.01
# Date created:		20 Oct 1996
# Whom:			Yukihiro Nakai <nakai@mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.4 1998/03/23 04:56:22 asami Exp $
#

DISTNAME=	txtmerge101
PKGNAME=	txtmerge-1.01
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.cs.uni-magdeburg.de/pub/www/xanime/ \
		ftp://ftp.doc.ic.ac.uk/computing/information-systems/WWW/xanime/

MAINTAINER=	nacai@iname.com

BROKEN=		build

WRKSRC=		${WRKDIR}/txtmerge
ALL_TARGET=	txtmerge

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/txtmerge ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/txtmerge
	${INSTALL_DATA} ${WRKSRC}/txtmerge.doc ${PREFIX}/share/doc/txtmerge

.include <bsd.port.mk>

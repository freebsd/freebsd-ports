# New ports collection makefile for:   gifmerge
# Version required:    1.33
# Date created:        20 Oct 1996
# Whom:                Yukihiro Nakai <nakai@mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1996/11/19 12:32:02 asami Exp $
#

DISTNAME=	gifmerge
PKGNAME=        gifmerge-1.33
CATEGORIES=     graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar

MAINTAINER=     nakai@mlab.t.u-tokyo.ac.jp

ALL_TARGET=	gifmerge
NO_WRKSUBDIR=	yes
EXTRACT_BEFORE_ARGS=	-xf

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/gifmerge ${PREFIX}/bin/gifmerge

.include <bsd.port.mk>

# New ports collection makefile for:	xsoldier
# Version required:	0.95
# Date created:		22 January 1997
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1997/02/16 10:54:55 andreas Exp $
#

DISTNAME=	xsoldier-0.95
CATEGORIES=	games x11
MASTER_SITES=	http://www.educ.info.kanagawa-u.ac.jp/~s945750/xsoldier/

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

CONFIGURE_ENV=	X11BASE=${X11BASE}
USE_X11=	yes

.include <bsd.port.mk>

# New ports collection makefile for:   guileobjc
# Version required:    0.3.8
# Date created:        21 April 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.6 1998/11/26 05:35:42 asami Exp $
#

DISTNAME=	guileobjc-0.3.8
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.aist-nara.ac.jp/pub/personal/masata-y/gyve/fullkit/gyve-0.1.2.4/

MAINTAINER=	nacai@iname.com

BUILD_DEPENDS=	${LOCALBASE}/lib/libobjects.a:${PORTSDIR}/lang/libobjects
LIB_DEPENDS=	guile.4:${PORTSDIR}/lang/guile

BROKEN=		Doesn\'t work with the latest guile.

GNU_CONFIGURE=	yes

.include <bsd.port.mk>

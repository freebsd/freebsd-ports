# New ports collection makefile for:   guileobjc
# Version required:    0.3.8
# Date created:        21 April 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $Id$
#

DISTNAME=	guileobjc-0.3.8
CATEGORIES=	devel
MASTER_SITES= 	ftp://ftp.aist-nara.ac.jp/pub/personal/masata-y/gyve/fullkit/gyve-0.1.2.4/

MAINTAINER=	Nakai@technologist.com

BUILD_DEPENDS=	${LOCALBASE}/lib/libobjects.a:${PORTSDIR}/devel/libobjects
LIB_DEPENDS=	guile\\.2\\.:${PORTSDIR}/lang/guile

GNU_CONFIGURE=	yes

post-install:
	${LDCONFIG} -m ${PREFIX}

.include <bsd.port.mk>

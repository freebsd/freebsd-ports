# New ports collection makefile for:   guileobjc
# Version required:    0.3.8
# Date created:        21 April 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.2 1998/09/24 05:04:06 vanilla Exp $
#

DISTNAME=	guileobjc-0.3.8
CATEGORIES=	lang
MASTER_SITES= 	ftp://ftp.aist-nara.ac.jp/pub/personal/masata-y/gyve/fullkit/gyve-0.1.2.4/

MAINTAINER=	Nakai@technologist.com

BUILD_DEPENDS=	${LOCALBASE}/lib/libobjects.a:${PORTSDIR}/lang/libobjects
LIB_DEPENDS=	guile.2:${PORTSDIR}/lang/guile

GNU_CONFIGURE=	yes

.include <bsd.port.mk>

# ports collection makefile for:   mikmod304
# Version required:    3.1.5
# Date created:        16 November 1998
# Whom:                yoshiaki Uchikawa
#
# $Id: Makefile,v 1.10 1998/12/08 16:19:31 vanilla Exp $
#

DISTNAME=	mikmod-3.1.5
CATEGORIES=	audio
MASTER_SITES=	http://www.multimania.com/miodrag/mikmod/

PATCH_SITES=	http://www.multimania.com/miodrag/mikmod/
PATCHFILES=	patch-mikmod-3.1.5-a
PATCH_DIST_STRIP=	-p1

MAINTAINER=	yoshiaki@kt.rim.or.jp

LIB_DEPENDS=	mikmod.1:${PORTSDIR}/audio/libmikmod

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		mikmod.1

.include <bsd.port.mk>

# ports collection makefile for:   mikmod304
# Version required:    3.1.5
# Date created:        16 November 1998
# Whom:                yoshiaki Uchikawa
#
# $Id: Makefile,v 1.11 1999/05/05 22:16:23 mharo Exp $
#

DISTNAME=	mikmod-3.1.5
CATEGORIES=	audio
MASTER_SITES=	http://www.multimania.com/miodrag/mikmod/mikmod/ \
		http://mikmod.darkorb.net/mikmod/

PATCH_SITES=	http://www.multimania.com/miodrag/mikmod/patches/ \
		http://mikmod.darkorb.net/patches/
PATCHFILES=	patch-mikmod-3.1.5-a patch-mikmod-3.1.5-b
PATCH_DIST_STRIP=	-p1

MAINTAINER=	yoshiaki@kt.rim.or.jp

LIB_DEPENDS=	mikmod.2:${PORTSDIR}/audio/libmikmod

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		mikmod.1

.include <bsd.port.mk>

# New ports collection makefile for:   zh-aterm
# Version required:	0.3.4
# Date created:		26 April 1999
# Whom:			Chia-Hsing Yu <davidyu@ken.csie.ntu.edu.tw>
#
# $Id$
#

DISTNAME=	aterm-0.3.4
PKGNAME=	zh-aterm-0.3.4
CATEGORIES=	chinese
MASTER_SITES=	http://members.xoom.com/sashav/aterm/ \
		http://www.tigr.net/afterstep/as-apps/download/aterm/

MAINTAINER=	davidyu@ken.csie.ntu.edu.tw

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-transparency --enable-background-image \
		--disable-delete-key --disable-backspace-key --enable-big5
MAN1=		aterm.1

.include <bsd.port.mk>

# New ports collection makefile for:	xzgv
# Date created:				7 Oct 2000
# Whom:					Norio Suzuki <nosuzuki@e-mail.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	xzgv
PORTVERSION=	0.5
CATEGORIES=	graphics
MASTER_SITES=	http://xzgv.browser.org/ \
			${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/graphics/viewers/X

MAINTAINER=	nosuzuki@e-mail.ne.jp

USE_GMAKE=	yes
USE_IMLIB=	yes

MAN1=		xzgv.1

post-install:
	strip ${PREFIX}/bin/xzgv
	install-info ${PREFIX}/info/xzgv ${PREFIX}/info/dir

.include <bsd.port.mk>
